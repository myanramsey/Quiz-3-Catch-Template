# Completing and Submitting this Assignment

## Video Tutorial
<!-- Setting up embed: -->
<!-- https://ardalis.com/how-to-embed-youtube-video-in-github-readme-markdown/ -->
[![Thumbnail for tutorial video](https://img.youtube.com/vi/R8-glh-Twh4/maxresdefault.jpg)](https://www.youtube.com/watch?v=R8-glh-Twh4)

## Which method should I choose?

Method 1 will have you set up with a working programming environment the quickest, and requires no set up on your computer by using cloud containers. You are limited to using VSCode, however, and there is a limit to the amount of time you can spend programming with it, although you are unlikely to run into it. Still, it enables you to work on your project anywhere and on any device, so long as you have a web browser.

Method 2 takes a bit more work as you might have to install some dependencies, but it enables you to use CLion (which tends to have better C++-specific features) in addition to a local VSCode instance with your preferred settings and extensions. If you want to work on your project on multiple devices, however, you need to make sure to sync your project with Git.

Method 3 is the simplest - it will work with any editor and on any computer so long as you have g++ installed, but you miss out on GUI integration as you have to run your tests and builds from the command line.

## Method 1: Github Codespaces (Easiest)
Provided with this Github page is a Codespaces template that allows you to develop, compile, debug, and test this programming quiz from the cloud, either in your browser or through VSCode on your desktop. It includes a provided installation of Catch2 so that you do not need to install any additional software or libraries to start working. 

To get started, simply click "Use this template" in the top right of the GitHub window, and then select the "Create a new repository" option to make a personal (private!) copy of the template to work in. From there, click the green "Code" button, then click the "Codespaces" tab, and then "Create codespace on main". This will then generate your very own Codespace to work with which operates much the same as VSCode. 

From here, you can either work in your browser, or open your Codespace through VSCode on your desktop and use any extra themes, settings, or extensions you might have installed.

**IMPORTANT: Watch the video if you have trouble running your tests! You must run your tests through the testing tab or CMake tab for VSCode to recognize Catch, *not* the play button in the top right of the editing window!**
See [this link](https://youtu.be/R8-glh-Twh4) for a video tutorial of the above and more detail on using the development environment in case you are unfamiliar with VSCode and CMake.

Note that you get 120 "core hours" per month by default, and 180 with a GitHub Premium account, included with the free [GitHub Student Developer Pack](https://education.github.com/pack). "Core hours" are calculated by multiplying the number of CPU cores in your virtual by the actual number of hours you use the software for. So, with the (perfectly sufficient) 2-core default, you get 60/90 hours of actual use, which should be plenty for this course. 

In the case that you do run out of hours or you simply no longer wish to use Codespaces, as long as you've been regularly committing to your GitHub repo, you can simply clone your work to your local machine and work on it the regular way, detailed below.

## Method 2: Local Development Environment
This is the "regular" way to work on programming quizzes and projects, and lets you use any IDE of your choosing, like CLion (my personal favorite). However, it depends on your local environment having all of the required packages and libraries, namely Git. Instructions are provided below, and you are welcome to ask any TA for help in setting up your computer, but if for whatever reason you are absolutely unable to get the toolchain set up, you should fall back on the Codespaces option, which is guaranteed to work.

Catch2 is automatically pulled in to your project by our CMakeLists.txt configuration, and should require no extra work on your part (given that you have git installed and working).

<!-- ### Installing Catch2 -->
<!-- The provided CMakeLists.txt build file assumes that you are using Catch2 v3, which has much improved testing speeds over the previous versions. Instructions for installing the library system-wide are provided below, partially adapted from [Catch2's documentation](https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md). -->

<!-- #### Windows (Currently Untested) -->
<!-- You can use the vcpkg package manager to install the library systemwide. Install instructions for vcpkg are provided [here](docs/cmake-integration.md), but in short, run the following commands from within your project directory: -->

<!-- ```cmd -->
<!-- > git clone https://github.com/microsoft/vcpkg -->
<!-- > .\vcpkg\bootstrap-vcpkg.bat -->
<!-- > .\vcpkg\vcpkg install catch2:x64-windows -->
<!-- ``` -->

<!-- This *should* make Catch2 avaiable to use within your project, but note that I do not have a Windows device to test this on. See the CMake install method below if this doesn't work. -->

<!-- #### MacOS (Also Untested) -->
<!-- Catch2 is available from [homebrew](https://brew.sh/), so making Catch2 available should be as simple as  -->

<!-- ```sh -->
<!-- brew install catch2 -->
<!-- ``` -->

<!-- , given that you have homebrew already installed and set up. -->

<!-- #### Linux -->
<!-- If available, you can install Catch2 with your distro's package manager, although it is likely to be fairly to extremely out of date. If the version is lower than 3, you should install from source like so (make sure you have cmake installed): -->

<!-- ```sh -->
<!-- #catch2 local install source: https://github.com/catchorg/Catch2/issues/1383#issuecomment-421548807 -->
<!-- cd -->
<!-- git clone https://github.com/catchorg/Catch2.git -->
<!-- cd Catch2 -->

<!-- #note that catch needs to be compiled against C++17, see here: https://stackoverflow.com/questions/66227246/catch2-undefined-reference-to-catchstringmaker -->
<!-- cmake -Bbuild -H. -DBUILD_TESTING=OFF -DCMAKE_CXX_STANDARD=17 -->
<!-- sudo cmake --build build/ --target install  -->
<!-- ``` -->

<!-- #### Platform-Independent CMake method -->
<!-- This method requires using CMake features to pull Catch2 in from GitHub and attach it to your project. This method involves changing the provided CMakeLists.txt file. A detailed written and video guide is available [here](https://github.com/COP3530/catch-with-cmake), but note that it is written with Project 1 in mind, so you'll have to translate some of the CMake content to the quiz setup instead.  -->

<!-- This method is more or less guaranteed to work, but takes some time to set up, and you may run into issues along the way. Treat this as a last resort if you can't get any of the easier methods above working for you.  -->

### IDE/Editor Setup

#### CLion
CLion works with Catch2 out of the box and as such requires no extra set up in your environment. Make sure your CLion is as up to date as possible, however, as there have been issues with older versions of CLion and newer versions of Catch 2.

At the bottom of the CMakeLists.txt file are some extra lines of setup code to integrate testing in VSCode. 

```cmake
include(CTest)
include(Catch)
catch_discover_tests(Tests) # must be named the same as your test executable
```

In case they cause issues with CLion, simply comment them out and reload your CMake configuration. 

See [here](https://github.com/COP3530/catch-with-cmake#part-3-integrating-with-clion) for more detail.

#### VSCode
Make sure that you have the following extensions installed on your VSCode.

- C/C++ (Microsoft)
- C/C++ Extension Pack (Microsoft)
- CMake Tools (Microsoft)
- CMake Language Support (either twxs or Jose Torres)

You must also install CMake itself to your system. CLion bundles a version of CMake with itself so this step is unnecessary if on CLion. Note that the version you install may be older that what CLion would package - if you get an error in your CMakeLists.txt about your CMake being too old, simply change this line

``` cmake
cmake_minimum_required(VERSION 3.24)
```

to have whichever version of CMake that you have installed.

Beyond this setup, the editing/testing process should be the same as outlined in the Codespaces tutorial video. More details are avaiable [here](https://github.com/COP3530/catch-with-cmake#part-3-alternate-integrating-with-vscode), although note that the suggested edits to the CMakeLists.txt file are already present in the template.

## Method 3: Commandline Testing (Simplest)

In test/test.cpp, replace the line at the top that reads `#include <catch2/catch_test_macros.hpp>` with this line:
```cpp
#include "catch/catch_amalgamated.hpp"
```

Also change the include for `interquartile_range.h` with a relative path, like so:
```cpp
#include "../src/interquartile_range.h"
```

Run this command once from your project directory:
```sh
g++ -std=c++14 -Werror -Wuninitialized -g -c test/catch/catch_amalgamated.cpp -o build/catch_amalgamated.o
```

Next, run these commands to build and view your tests:
```sh
g++ -std=c++14 -Werror -Wuninitialized -g build/catch_amalgamated.o test/test.cpp -o build/test
./build/test
```
If you make any changes to your files, you can run the last two commands again.
You do not need to run the first command again.

# Assignment Description: Interquartile Range

Quartiles are used in statistics to classify data. 
Per their name, they divide data into quarters.   

Given a set of data: [1, 2, 3, 4, 5, 6, 7] 
 
The lower quartile (Q1) would be the value that 
separates the lowest quarter of the data from
the rest of the data set. So, in this instance, 
Q1 = 2. The middle quartile (also known
as the median or Q2) separates the lowest 2 quarters
of the data from the rest of the data set. In
this case, Q2 = 4. The upper quartile (Q3) 
separates the lowest 3 quarters of the data 
from the rest of the data set. In this case, Q3 = 6.
The interquartile range (IQR) is the difference between
the third quartile and the first quartile: Q3 - Q1. 

In case the number of values in the list are *odd*,
the central element is a unique element. 
Example, if the list has *size = 9*. 
The *fifth element* in the list will be the median.
In case the number of values in the list are *even*, 
the central element is a average of two elements. 
Example, if the list has *size = 10*. 
The *average of fifth and sixth element* in the
list will be the median. Q1 is the median of 
the beginning and the element preceding median,
 and Q3 is the median of the element succeeding
  median and the end. 

Another example, if the data were [1, 2, 3, 4]
- Q2 = Average of 2 and 3 = 2.5
- Q1 = List consisting of elements: 1, 2 (everything before median) = Average of 1 and 2 = 1.5
- Q3 = List consisting of elements: 3, 4 (everything after median) = Average of 3 and 4 = 3.5
- IQR = 3.5 - 1.5 = 2.00

&nbsp;
***
&nbsp;


## Problem Statement
Given a sorted singly linked list without a tail 
(e.g, head -> 1 -> 2 -> 3 -> 4), return the 
interquartile range of the data set using 
the slow and fast pointer approach OR 
using a methodology that does not iterate 
over the linked list twice. **You must not iterate 
over the entire linked list more than once and you
cannot use arrays, vectors, lists or an STL 
implementation of List ADT in this problem.** 
If you prohibit the above requirements, you will
incur a 20% penalty on your score.   

The following Node class is already defined 
for you and we have already implemented the 
insert() and main() function:

```c++
class Node {
    public:
        int value;
        Node* next = nullptr;
};
```

### Restriction:
For this problem, we ask that you use properties of lists rather than using another container,
for example you cannot move all of the elements into a vector and then find the IQR of the vector.
Additionally, you should not count the elements of the list and use this count
to determine the locations of Q1 and Q3 in the list (e.g. count/4 and 3*count/4).
Instead, you should use the properties of linked lists and list traversal ideas we've brought up
in class/discussion to solve this problem.
(Hint: Think about how you can adapt the slow/fast pointer technique to solve this problem).

Some examples of acceptable code structures would be
using one loop with any number of conditionals outside the loop,
or using a divide and conquer approach.

Note: When using fast/slow pointer to find a median,
you may use the size of the list to see if it's even or odd,
as this determines how you will find the median.
If you are counting the nodes in the list to use it in this capacity,
it is acceptable for this problem.
**Any other use of a count for this problem is not allowed.**

### Sample Input:
```c++
2 4 4 5 6 7 8
```

### Sample Output:
```c++
3.00 
```

### Explanation:
- Input is a set of numbers inserted into a 
Linked List separated by spaces.
- The head of this linked list is passed into the 
 interQuartile() function. 
- Output is the Interquartile Range of the list, 
a floating point value. IQR = Q3-Q1 = 7-4 = 3.00. 
We are rounding returned values to two decimal 
places in main using setprecision().
- Note you are expected to return a floating point
 value. Also, there are a a variety of definitions 
 of IQR and we will use the definition listed here: https://www.calculatorsoup.com/calculators/statistics/quartile-calculator.php 
- You can use the calculator at above link to generate
 sample test cases.

### Constraints
- The list can contain any integers.
- The list will have at least 4 values.
- The list is sorted.

### Difficulty
Hard (+60 minutes)  

**Author:** `Robert Casanova and Amanpreet Kapoor`, 
**Date Created:** `13 Sep 2020`, 
**Last Modified:** `10 Sep 2022`
