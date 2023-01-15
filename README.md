# WebsiteGenerator

Link to the project [Trello board](https://trello.com/b/uUxYKlrv/website-generator).

Link to [git help](https://education.github.com/git-cheat-sheet-education.pdf).

Deadline for website part is **November 20th 2022**.

Deadline for C programming part is ***around December 4th 2022***.

Deadline for finalisation part is ***around December 28th 2022***.

## Prerequisites

This project requires NodeJS (version 18 or later) and NPM.
[Node](http://nodejs.org/) and [NPM](https://npmjs.org/) are really easy to install.
To make sure you have them available on your machine,
try running the following command.

```sh
$ npm -v && node -v
8.19.2
v18.12.1
```

***If you want to compile the generator app yourself you need to have cmake, make and any c compiler(preferably gcc) installed on your machine.***

```sh
$ cmake --version
cmake version 3.16.3
$ make --version
GNU Make 4.2.1
$ gcc --version
gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
```

## Installation

**BEFORE YOU INSTALL:** please read the [prerequisites](#prerequisites)

Start with cloning this repo on your local machine:

```sh
$ git clone https://github.com/imbieras/WebsiteGenerator.git
$ cd WebsiteGenerator
```

Download all the packages

```sh
$ npm ci
```

## Usage

### Generating the website

```sh
$ cd app
$ cmake -S . -B build  # alternatively use cmake -S . -B build -G "MinGW Makefiles"
$ cd build
$ make
```

### Theming

The websites theme can be changes by changing according variables located at `./src/assets/scss/abstracts/_variables.scss`.

```scss
$primary: #78003f;
$secondary: #e64164;
$light: #f1f1f1;
$dark: #414141;
$white: #ffffff;
```

_After changing the theme you may need to delete files in `./dist/`, since remenants can be left behind._

### Serving the app

```sh
$ npm run dev
```

### Building a distribution version

```sh
$ npm run dev build
```

This task will create a distribution version of the project
inside your local `./dist/` folder

### Clean up packages

```sh
$ npm run clean
```

### Upload to GitHub pages

```sh
$ npm run deploy
```
