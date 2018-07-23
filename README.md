# Unit Test Framework Exploration

## Frameworks Evaluated
- Google Test
- Boost Test
- Catch 2

## Mocking Libraries Evaluated
- Google Mocks
- FakeIt

## ECS
TBD


## Build Instructions

#### Windows - Visual Studio 2017
**Prerequisites**
- Visual Studio 2017 
  - Minimum 15.7.5
  - Preferrably 15.8 Preview 4 or 15.8 when released
  - Extensions (install via Tools:Extensions and Updates):
    - Markdown Editor
    - Google Test Adapter (installed with Visual Studio since 15.5)
    - Boost Test Adapter (installed with Visual Studio since 15.5)
    - Catch2 Test Adapter (get the latest [here](https://marketplace.visualstudio.com/items?itemName=JohnnyHendriks.ext01))
    
**Build it** 
- ```File:Open:Folder```, select the folder containing the ```CppCrossPlatformTests``` folder 
- Make sure the ```x64-Debug``` target is selected
- Make sure the CMake project knows where to find the correct version of Boost:
  - The project expects the following folders under the Boost root folder:
      - ```include/boost``` - contains folders with headers for each Boost lbrary
      - ```vs141-x86/lib``` - contains all the static and dynamic libs built for VS 2017 x86
      - ```vs141-x64/lib``` - contains all the static and dynamic libs built for VS 2017 x64
  - Preferred method:
    - Define the environment variable ```OVERRIDE_BOOSTROOTDIR``` to point to the root folder of the version of boost you want to use
  - Or change the ```CMAkeSettings.json``` file 
    - ```CMake:Change CMake Settings:CppCrossPlatformTests\CMakeLists.txt```
    - Change ```environments.BoostRootDir``` to point to the correct version of Boost on your machine 
  - NB: This project has been tested only with **Boost 1.67.0**
- CMake should automatically build the CMake Cache, if not:
  - ```CMake:Cache (x64-Debug only):Generate:CppCrossPlatformTests\CMakeLists.txt```
- ```CMake:Rebuild All```

#### Linux - Command Line

## Running Tests

#### Windows - Visual Studio 2017
**Run all tests to see if they all pass**
- ```CMake:Tests:Run Project CTests```
- Results are shown in the ```Output (CMake)``` pane of Visual Studio

**Use a Test Runner**
- ```Test:Run:All Tests```
- Results are shown in the traditional red/green style in the ```Test Explorer``` pane (```Test:Windows:Test Explorer```)

#### Linux - Command Line

## Folders in this project
- ```CppCrossPlatformTests```
  - ```Catch2``` - The Catch 2 C++ unit testing library sources
  - ```cmake``` - CMake scripts
  - ```ECS``` - Entity Component System library, a simple, stand-alone example C++ library included for demonstration purposes
  - ```FakeIt``` - The FakeIt C++ unit test mocking library
  - ```googletest``` - The Google Test C++ unit testing library (includes Google Mocks mocking library)
  - ```SimpleMockExample``` - A very simple example C++ interface and implementing class, with another class that uses it
  - ```TestExamples_BoostTest``` - Unit testing examples using Boost Test 
  - ```TestExamples_Catch``` - Unit testing examples using Catch 2 
  - ```TestExamples_GoogleTest``` - Unit testing examples using Google Test 
  - ```CMakeLists.txt``` - the top-level CMake file for the whole project
  - ```CMakeSettings.json``` - CMake settings file - you can set the location of Boost here
  - ```README.md``` - this file 
