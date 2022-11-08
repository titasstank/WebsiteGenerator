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

### Serving the app

```sh
$ npm run dev
```

### Building a distribution version

```sh
$ npm run build
```

This task will create a distribution version of the project
inside your local `dist/` folder

### Clean up packages

```sh
$ npm run clean
```

### Upload to GitHub pages

```sh
$ npm run deploy
```
