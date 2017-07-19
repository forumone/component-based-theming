# Component-based Theming with Twig

This repository is for using a Composer based workflow with Drupal 8.  We will be using this repository and the branches to maintain various snapshots as we progress thru each lesson.  Below is a list of requirements that will ensure you get the most out of the training.

Please ensure that you follow the directions outlined as we will not be able to cover these steps in class nor stop class to assist with setting up laptops.

## Requirements

 - Administrative rights to install and configure various applications
 - Acquia Dev Desktop
 - Composer
 - NPM
 - Grunt

### Acquia Dev Desktop


### Composer
You will also need to ensure you have globally installed `Composer` as we will be using this to manage Drupal 8.

### NPM

### Grunt

### Acquia Dev Desktop

### Cloning the repo

### Installing Drupal 8

### Importing the Database





2) You will also need to ensure you have globally installed `Composer`, `Drush` and/or `Drupal Console` as these tools will be used to install Drupal and run various commands such as enabling PHP's built-in server and clearing Drupal's cache.
    * OSX and Linux users can refer to the [Development Workflow](https://github.com/chazchumley/component-training/blob/master/docs/developer-workflow.pdf) document to assist you with globaly installing Composer, Drush and Drupal Console.

3) Finally as we will be working with Pattern Lab, Sass and Twig we will need to ensure we can use `npm` and `grunt` which requires that both [nodejs](https://nodejs.org/en/) and [grunt-cli](https://gruntjs.com/getting-started) are installed.

Once your environment is configured you can easily create a Drupal 8 project by opening a terminal window, changing into the project root directory and running the following commands:
```
composer install
composer drupal-scaffold
```
The `composer install` command reads the `composer.json` file to install Drupal 8 and any dependencies it needs.  Any contributed modules will also be installed and the Drupal directory structure will be scaffolded.

To test PHP's built-in webserver can be run, enter the following command in the terminal window.

```
cd web
drush rs
```

To start PHP's built-in webserver using Drupal Console, run the following command.

```
drupal server
```

## Acquia Dev Desktop (Windows, OSX)
1) Download and install [Acquia Dev Desktop](https://dev.acquia.com/downloads)
2)

# Lesson Two: Tools
During this lesson we will be reviewing various tools such as Git to clone our themes repo to our project, Composer to create a Pattern Lab project within our theme, NPM to install theme dependencies and finally Grunt to help build our theme's assets.

OSX and Linux users will want to instal these tools globally.  Windows users I would recommend using [Drupal VM](https://www.drupalvm.com/) which has these tools packaged within a virtual environment.

## Node & NPM
[Node](https://nodejs.org/en/) is a cross platform runtime environment for creating server side and networking applications. Javascript running outside the browser.  [NPM](https://www.npmjs.com/) is the package manager for JavaScript used to install, share, and distribute code and is used to manage dependencies in projects.

To intall `Node JS` and `NPM` globally we can follow the directions on the [download](https://nodejs.org/en/download/) page using one of the current installers.  Installing `Node JS` will automatically install `npm` as well.
We can vaidate that both are installed by running the following commands in the terminal window.

```
node -v
npm -v
```

## Grunt
`Grunt` is a JavaScript task runner that allows you to perform repetitive tasks like minification, compilation, unit testing, linting and more.  We use `Grunt` to compile Sass, Pattern Lab and watch for file changes during development.
We can use `npm` to globally install `grunt` by using the following command in the terminal window.

```
npm install -g grunt-cli
```

## Gesso
Gesso is a [Sass](http://sass-lang.com/)-based starter theme that outputs accessible HTML5 markup. It uses a mobile-first responsive approach and leverages [SMACSS](https://smacss.com/) to organize styles as outlined in the
[Drupal 8 CSS architecture guidelines](https://www.drupal.org/node/1887918).
This encourages a component-based approach to theming through the creation of discrete, reusable UI elements.
We can clone the `Gesso` repo to our `/web/theme/` folder by running the following command within the terminal window.

```
cd web/themes
git clone git@github.com:forumone/gesso.git gesso
cd gesso
```
Since we are cloning the gesso theme into our git repo we will also want to remove the git file from `gesso` to avoid any issues.  Withing the terminal window, run the following command:

```
rm -rf .git
```
## Pattern Lab
At its core, Pattern Lab is a static site generator (powered by either PHP or Node) that stitches together UI components. But there's a whole lot more to it than that as we will find out once we begin looking at components.
We can install Pattern Lab directly into our theme using `composer` to create a Pattern Lab project by entering the following commands within our terminal window.

```
composer create-project pattern-lab/edition-drupal-standard pattern-lab
```
If prompted, select `r` to overwrite existing `/source/` files.

### Forum One starter kit
When prompted, select `forumone/starterkit-twig-drupal-gesso` as the starterkit which is option 4.
If prompted, select `r` to overwrite existing `/source/` files.

### NPM Packages
Next we will need to use `npm` to install any theme dependencies and packages that both our theme and Pattern Lab will need to build our assets.  We can install packages by entering the following command within the terminal window.

```
npm install
```
### Grunt
Finally we will need to build our assets by entering the following command within the terminal window.

```
grunt gessoBuild
```

## Configuring Drupal for local development
With our theme in place and Pattern Lab working, we now need to configure Drupal for local development.  This generally involves modifying the `settings.php` file and creating `settings.local.php` and `local.services.yml` to allow for both disbaled caching and to enable Twig debugging.

Anytime we manage settings files we will need to have the proper file permissions. Make sure you can either change the permissions of the files or folders we will need to access or that you can authenticate when saving or creating files.

### Settings.php
If we open up our `settings.php` file and scroll to the bottom we will see a section commented out that refers to local development override configuration.  Once we uncomment this section Drupal will look for a new file to include called `settings.local.php`.  Go ahead and uncomment the section or replace your current `settings.php` file with the [gist](https://gist.github.com/chazchumley/c98fc6b89d26bc5155c19022e2059fc0) we have created.  Also since our settings.local.php file includes the database settings we will want to remove that section from `settings.php` so that we don't have duplicate database credentials.

### settings.local.php
Since our settings file is now looking for a new file we will need to create the `settings.local.php` file by copying the [gist](https://gist.github.com/chazchumley/69d0236fe6c54e6d6ee967753c5b5c5f) and placing it within the `/sites/default/` folder.

### local.services.yml
The last step is to add the [gist](https://gist.github.com/chazchumley/2a113123e983669d592ecc2581784a72) for our new local.services.yml file which will allow us to enable and disable Twig debugging.

We will review each of the settings, settings.local and local services files in more detail in class.
