#!/usr/bin/env python
import glob
import configparser
import os
import sys


# You can find documentation for SCons and SConstruct files at:
# https://scons.org/documentation.html

# This lets SCons know that we're using godot-cpp, from the godot-cpp folder.
env = SConscript("godot-cpp/SConstruct")

# Get all subdirectories inside 'src'
include_dirs = ["src"] # Start with the root 'src' folder
for root, dirs, files in os.walk("src"):
    for d in dirs:
        include_dirs.append(os.path.join(root, d))

# Configures the 'c_cpp' directory as a source for header files.
env.Append(CPPPATH=include_dirs)
print(include_dirs)

# Collects all .cpp files in the 'src' folder as compile targets.
native = glob.glob("src/**/*.cpp", recursive=True)
sources = [env.File(path) for path in native]

platform_info = sys.platform
lib_name = "WHAA"
project_dir = "project"
FileName_dotgdextension = "WHAA.gdextension"
entry_symbol = '"WHAA_init"'
compatibility_minimum = '"4.7"'

path_gdextension = os.path.join(project_dir, FileName_dotgdextension)
bin_dir = os.path.join(project_dir, "bin")
windows_dir = os.path.join(bin_dir, "windows")
macos_dir = os.path.join(bin_dir, "macos")
ios_dir = os.path.join(bin_dir, "ios")
linux_dir = os.path.join(bin_dir, "linux")
android_dir = os.path.join(bin_dir, "android")

os.makedirs(bin_dir, exist_ok=True)
os.makedirs(windows_dir, exist_ok=True)
os.makedirs(macos_dir, exist_ok=True)
os.makedirs(ios_dir, exist_ok=True)
os.makedirs(linux_dir, exist_ok=True)
os.makedirs(android_dir, exist_ok=True)

def create_config():
    # Platform = ["windows", "linux", "android", "macos", "ios"]
    # Architecture = ["x86_64", "x86_32", "arm64", "arm32"]
    config = configparser.ConfigParser()
    config.optionxform = str

    if os.path.exists(path_gdextension):
        config.read(path_gdextension)

    if "configuration" not in config:
        config["configuration"] = {}

    
    config["configuration"]["entry_symbol"] = entry_symbol
    config["configuration"]["compatibility_minimum"] = compatibility_minimum

    if "libraries" not in config:
        config["libraries"] = {}

    isdebug = "debug" in str(env["target"]).lower()
    build_type = "debug" if isdebug else "release"

    if env["platform"] == "macos":
        macos = "{}.{}".format(env["platform"], build_type)
        libmacos = '"res://bin/{}/lib{}.{}.{}.framework/lib{}.{}.{}"'.format(
                    env["platform"], lib_name, env["platform"], env["target"],
                    lib_name, env["platform"], env["target"]
                )

        config["libraries"][macos] = libmacos
    elif env["platform"] == "ios":
        if env["ios_simulator"]:
            iosSim = "{}.{}".format(env["platform"], build_type)
            libiosSim = '"res://bin/{}/bin/lib{}.{}.{}.simulator.a"'.format(
                            env["platform"], lib_name, env["platform"], env["target"]
                        )

            config["libraries"][iosSim] = libiosSim
        else:
            ios = "{}.{}".format(env["platform"], build_type)
            libios = '"res://bin/{}/lib{}.{}.{}.a"'.format(
                            env["platform"], lib_name, env["platform"], env["target"]
                        )

            config["libraries"][ios] = libios
    else:
        etc = "{}.{}.{}".format(env["platform"], build_type, env["arch"])
        libetc = '"res://bin/{}/lib{}{}{}"'.format(
                    env["platform"], lib_name, env["suffix"], env["SHLIBSUFFIX"]
                )

        config["libraries"][etc] = libetc
        
    with open(path_gdextension, "w") as config_file:
        config.write(config_file)

create_config()

# Add LZ4 library dependency
if platform_info == 'darwin': # macos
    env.Append(LIBPATH=["/usr/local/lib"])
    env.Append(CPPPATH=["/usr/local/include"])

env.Append(LIBPATH=["#static_libs"])
env.Append(LIBS=["liblz4_static"])  # download https://github.com/lz4/lz4 then place your path

if env["platform"] == "macos":
    library = env.SharedLibrary(
        "{}/{}/lib{}.{}.{}.framework/lib{}.{}.{}".format(
            bin_dir, env["platform"], lib_name, env["platform"], env["target"],
            lib_name, env["platform"], env["target"]
        ),
        source=sources,
    )
elif env["platform"] == "ios":
    if env["ios_simulator"]:
        library = env.StaticLibrary(
            "{}/{}/lib{}.{}.{}.simulator.a".format(
                bin_dir, env["platform"], lib_name, env["platform"], env["target"]
            ),
            source=sources,
        )
    else:
        library = env.StaticLibrary(
            "{}/{}/lib{}.{}.{}.a".format(
                bin_dir, env["platform"], lib_name, env["platform"], env["target"]
            ),
            source=sources,
        )
else:
    library = env.SharedLibrary(
        "{}/{}/lib{}{}{}".format(
            bin_dir, env["platform"], lib_name, env["suffix"], env["SHLIBSUFFIX"]
        ),
        source=sources,
    )

# Selects the shared library as the default target.
Default(library)
