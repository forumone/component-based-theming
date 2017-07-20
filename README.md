# Component-based Theming with Twig
This repository is for using a Composer based workflow with Drupal 8.  We will be using this repository and the branches to maintain various snapshots as we progress thru each lesson.

Please ensure that you follow the directions outlined below to install and configure the necessary requirements for this training. We will not be able to cover these steps in class nor will we have time to stop class to assist with setting up laptops.

Below is a list of requirements that will ensure you get the most out of the training.

## Requirements
- Administrative rights to install and configure various applications
- Acquia Dev Desktop
- Terminal
- Composer
- Node & NPM
- Grunt
- Git

### Acquia Dev Desktop

To eliminate the need for various setups that may involve different ***AMP** (Apache/MySQL/PHP) stacks we will be using Acquia Dev Desktop to work with PHP, MySQL and Drupal.  We can download and install Dev Desktop for both Windows and MAC by navigating to the [download](https://dev.acquia.com/downloads) page and following the install prompts for our operating system.

Once complete we will revisit how to use Acquia Dev Desktop to import a Drupal 8 website as well as how to import database snapshots that we will use throughout the training.

### Terminal

The terminal is an interface in which we can type and execute text based commands.  It can be much faster to complete some tasks using a Terminal than with graphical applications and menus. The remaining requirements will all be ran from a Terminal using a series of command line prompts.  Take a moment to ensure that we have a Terminal (MAC) or Command Prompt (Windows) available to use.

We will be using the terminal window to work with `Composer`, `NPM`, `Grunt` and `Git` throughout the training.  It is important to be comfortable using the command line as it should be part of our daily Front End development workflow.

### Composer

Composer (https://getcomposer.org/) is a dependency manager for PHP that allows us to perform a multitude of tasks; everything from creating a Drupal project to declaring libraries and even installing contributed modules, just to name a few. The advantage of using Composer is that it allows us to quickly install and update dependencies by simply running a few commands from a terminal window.

Composer can be installed on Windows, Linux, Unix, and OS X. For this training, we will be following the installation directions found at https://getcomposer.org/download/.  Take a look at the **Getting Started** documentation that corresponds with our operating system.


> We will want to ensure that Composer is installed globally on our operating system.

Once Composer has been installed globally we should be able to open a terminal window and enter the following command to see a list of the Available commands:


    composer

### Node & NPM

[Node](https://nodejs.org/en/) is a cross platform runtime environment for creating server side and networking applications. Javascript running outside the browser. [NPM](https://www.npmjs.com/) is the package manager for JavaScript used to install, share, and distribute code and is used to manage dependencies in projects.


> We will be using NPM to manage dependencies when working with themes in Drupal 8.

We can install `Node JS` and `NPM` globally by following the directions on the [download](https://nodejs.org/en/download/) page and using one of the current LTS installers for our current operating system.  Installing `Node JS` will automatically install `NPM` as well.

We can validate that both are installed by running the following commands in the terminal window:


    node -v
    npm -v

### Grunt

[Grunt](https://gruntjs.com/) is a JavaScript task runner that allows us to perform repetitive tasks like minification, compilation, unit testing, linting and more. We use `Grunt` to compile Sass, Pattern Lab and watch for file changes during development. 

We can use `npm` to globally install `grunt` by using the following command in the terminal window:


    npm install -g grunt-cli

### Git

[Git](https://git-scm.com/) is probably the most popular open source software available to manage source code. Git allows us to distribute code to ourselves or other developers and provides a robust mechanism for tracking changes, creating branches, and staging changes to software, or in our case, web projects.

We can install `Git` by following the directions on the [download](https://git-scm.com/downloads) page and using on the installers for our current operating system.

We can validate that `Git` is installed properly by running the following command in the terminal window:


     which git


> Git for Windows provides a BASH emulation used to run Git from the command line. *NIX users should feel right at home, as the BASH emulation behaves just like the `git` command in LINUX and UNIX environments. 


## Cloning the training files

Now that we have all the necessary requirements out of the way we can proceed to cloning a copy of the training files located within the Master branch.  We will be using the `Terminal` window and `Git` during different exercises to make sure everyone is at the same starting point.

Begin by opening a terminal window and navigating to a location on our laptop where we will be working from.  The location does not matter but for sake of demonstration, I will be using a folder called **Sandbox**.  To change into this directory we will enter the following command within the terminal window:


    cd Sandbox

Now that we have changed into the Sandbox directory we can clone the Master branch by entering the following command within the terminal window:


    git clone git@github.com:forumone/component-based-theming.git

To verify that our newly cloned folder exists we can enter the following command within the terminal window to list the contents of our Sandbox:


    ll

Finally we will want to change into the component-based-theming folder by entering the following command within the terminal window:


    cd component-based-theming


## Using Composer to install Drupal

Currently we have the skeleton of a Drupal 8 project.  The main reason for using a Composer based workflow recommended by Drupal is to ensure that our codebase or repository contains minimal artifacts or files.  In fact if we take a quick look at the folder structure we will see the following:

- **config/sync** : Configuration files that we can use to manage Drupal instances
- **db** : Database snapshots that we will use throughout the training
- **drush**: A command line tool we will use to clear cache and other tasks with Drupal
- **scripts/composer**: Composer scripts that run to automate various tasks
- **web**: Drupal’s web root where we will find all it’s files including the Theme directory

Also if we look we will see a file called `composer.json` which is often referred to as a package.  The `composer.json` file allows us to manage Drupal core, Modules and dependencies, patches that a module may need and various other settings.  It is the `composer.json` file that allows us to distribute a Drupal project to team members that will ensure every Drupal instance is identical.

To complete the scaffolding of our Drupal 8 project we will need to open a terminal window and run the following command:


    composer install

Once composer is done running, we now have a fully installed Drupal 8 project.

## Importing our project into Acquia Dev Desktop

Now that we have a Drupal 8 project we can use Acquia Dev Desktop to import an existing Drupal 8 site into our self-contained environment by following these steps:

### Step One

Open Acquia Dev Desktop

- Select the + sign located in the bottom left of the UI
- Select **Import local Drupal site.**

### Step Two

Complete the following fields to import our Drupal instance:

- Local codebase folder: This should point to the `/web` root of our cloned project
- Local site name: **pwc**
- Use **PHP: 7.0.14**
- Database: Start with MySQL database dump file
- Dump file: Browse to the `/db` folder within our cloned project and select `pwc.sql`
- Select the OK button
- Select Yes from the Warning dialog box


> You may be prompted to enter your admin credentials to complete the process.

### Step Three

We can now preview our Drupal 8 website by either selecting the URL next to Local site within Acquia Dev Desktop or by opening a browser and navigating to http://pwc.dd:8083/user and logging in with the following credentials:

- username: **admin**
- password: **admin**


## Congratulations

We now have a Drupal 8 project titled Pacific Whale Conservancy that we will be using throughout the remaining training.  This Drupal 8 instance is configured with the latest best practices in mind for site building.  This includes use of the Media module, Paragraphs, various Twig modules and the Component and UI Libraries modules.

This training does not cover site building but we will briefly discuss various decision made when implementing a component-based theme using Twig and Pattern Lab.
