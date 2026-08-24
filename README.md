# godot-cpp-examples

* Godot Engine
  
	Website: https://godotengine.org/

	Github: https://github.com/godotengine/godot

##

* SConstruct
	> lib_name = "WHAA" (your library name)
	>> project_dir = "project" (your project folder)
	>>> FileName_dotgdextension = "WHAA.gdextension" (your name 'WHAA', dont forget to put .gdextension)
	>>>> entry_symbol = '"WHAA_init"' (if you change this, change the src/register_types.cpp too, it may got error in godot engine)
	>>>>> compatibility_minimum = '"4.7"' (version of your godot engine, like 4.4, 4.5, 4.6, 4.7, etc. dont do this like 4.4.0, 4.5.0, 4.6.0, 4.7.0, etc. it may got error in godot engine)

##

## Requirements

### 1. GitHub Account & Git
* [GitHub Account](https://github.com/): Required if you plan to use GitHub Actions for automated cross-platform compilation.
* [Git](https://git-scm.com/downloads): latest version, available in your **system environment PATH**: Installed on your machine and configured with your credentials so you can push changes to your remote repository.

### 2. Python & SCons (Build System)

- [Python](https://www.python.org/) latest version, available in your **system environment PATH**.

	- **Windows**: During the Python installer setup, make sure to check the box that says "Add Python to PATH" at the very bottom of the installer window. If you missed this, re-run the installer, choose "Modify", and check it.
	- **macOS**: `brew install python` (via Homebrew) or download from python.org.
	- **Arch Linux** / **CachyOS**: `sudo pacman -S python`
	- **Ubuntu** / **Linux Mint** / **Pop!_OS** / **Debian**: `sudo apt install python3 python3-pip`
	- **Fedora** / **RHEL** / **CentOS**: `sudo dnf install python3 python3-pip`

- [Scons](https://scons.org/) latest version, available in your **system environment PATH**.

	- **Windows**: `python -m pip install scons` or `py -m pip install scons`
	- **macOS**: `python3 -m pip install --user scons` (or via Homebrew: `brew install scons`)
	- **Arch Linux** / **CachyOS**: `sudo pacman -S scons`
	- **Ubuntu** / **Linux Mint** / **Pop!_OS** / **Debian**: `sudo apt install scons`
	- **Fedora** / **RHEL** / **CentOS**: `sudo dnf install scons`
	- **Other Linux / Fallback**: `python3 -m pip install --user scons`

### 3. C++ Compiler

- **Windows:** MSVC (Microsoft Visual C++) via Visual Studio or Build Tools.
	> [**[Download Visual Studio](https://visualstudio.microsoft.com/downloads/)**] (if download is finished/done, open it, and read 'downside')
	>> (select/click Desktop development with c++,
	>>> select Windows 11 SDK (latest-version) 'Download it first',
	>>>> click/select 'on top' Individual components,
	>>>>> search 'MSVC Build Tools for (Latest)', select(all) and Download.)
	>>>>>> #

- **macOS**: Clang (included with Xcode Command Line Tools: `xcode-select --install`).

- **Linux**: GCC or Clang (install your distro's standard development group):

	- **Arch Linux** / **CachyOS**: `sudo pacman -S base-devel`
	- **Ubuntu** / **Linux Mint** / **Pop!_OS** / **Debian**: `sudo apt install build-essential`
	- **Fedora** / **RHEL** / **CentOS**: `sudo dnf groupinstall "Development Tools"`




### 4. Code Editor

* **[Visual Studio Code](https://code.visualstudio.com/)** (with clangd extension, code faster)
* **[Zed](https://zed.dev/)** (works with Clangd by default)
* **[Visual Studio](https://visualstudio.microsoft.com/downloads/)** (if you know how to use)

##

# if you use vscode(Visual Studio Code).

* git
	> create your folder first.
	> git clone (Creates a local copy of an existing remote repository)
	```
	git clone -b 10.0.0-rc1 https://github.com/godotengine/godot-cpp
	```
	Change the '10.0.0-rc1' to latest version, check on [godot-cpp](https://github.com/godotengine/godot-cpp/)
 	> **Windows, Linux and macos**
  	```
	cd godot-cpp
	```
   	> git checkout (Fetch all tags and Checkout the Specific Version)
	```
 	git fetch --tags
	git checkout 10.0.0-rc1
	```
	Change the '10.0.0-rc1' to latest version, check on [godot-cpp](https://github.com/godotengine/godot-cpp/)
	> git submudole (Checkout the Specific Version)
	```
	git submodule update --init --recursive
	```



#

# scons
* Compile the godot-cpp

```
scons platform=macos api_version=4.7
```
```
scons platform=ios api_version=4.7
```
```
scons platform=windows api_version=4.7
```
```
scons platform=linux api_version=4.7
```
```
scons platform=android api_version=4.7
```


* Compile the godot-cpp for editor (this important so no error highlight for clangd)
```
scons platform=macos target=editor compiledb=yes
```
```
scons platform=ios target=editor compiledb=yes
```
```
scons platform=windows target=editor compiledb=yes
```
```
scons platform=linux target=editor compiledb=yes
```
```
scons platform=android target=editor compiledb=yes
```

Change the '4.7' version of your godot engine [godotengine](https://godotengine.org/)

#

* **Windows**
	> (if scons 'command' not working,
	>> press 'window icon' on your keyboard,
	>>> search env and open it,
	>>>> click 'Environment Variables',
	>>>>> duoble click 'path' in system variables,
	>>>>>> click 'New',
	>>>>>>> paste '%AppData%\Python\Python313\Scripts')
	>>>>>>>> if still not working,
	>>>>>>>>> i think the '%AppData%\Python\Python313\Scripts' invalid,
	>>>>>>>>>>  try find it your self.
	>>>>>>>>>>> #

#

* platform=(what platform, Default template_debug and default architecture)
```
scons platform=macos
```
```
scons platform=ios
```
```
scons platform=windows
```
```
scons platform=linux
```
```
scons platform=android
```

#

* arch=(what architecture)
```
scons platform=auto arch=x86_64
```
```
scons platform=auto arch=x86_32
```
```
scons platform=auto arch=arm64
```
```
scons platform=auto arch=arm32
```


#

* target=template_debug (Debugging your library)
```
scons platform=windows target=template_debug
```

#

* target=template_release (uses for final library or final game)
```
scons platform=auto target=template_release
```
#

* if you using vs(Visual Studio), just watch tutorial.
