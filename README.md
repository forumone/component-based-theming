# 02-Tools

# Component-based Theming with Twig

This repository is for using a Composer based workflow with Drupal 8.  We will be using this repository and the branches to maintain various snapshots as we progress thru each lesson.

## Assumptions

This training assumes that you are already running Acquia Dev Desktop and have a familiarity with installing Drupal using the standard means of downloading, setting up a database, configuring a localhost, and completing the browser-based install. In the [Master](https://github.com/forumone/component-based-theming/tree/master#component-based-theming-with-twig) repo, we walked through quickly installing **Acquia Dev Desktop**, **Terminal**, **Composer**, **Node & NPM**, **Grunt**, and **Git**. Ensure that you have a working AMP stack and are comfortable working within the command-line interface using a Terminal window before continuing.

## Lesson Two: Tools

The term Front-end developer means so much more than someone who writes HTML, CSS, and JavaScript.  We will take a look at tools such as Composer, PatternLab, NPM and Grunt to help us work smarter when creating a theme in Drupal.  Beginning with using the very accessible Gesso theme to create a workflow that will assist us in creating our first components.

**Topics covered**

- Working with the Gesso theme
- Using Composer to create a PatternLab project
- Choosing a Drupal based Starterkit
- Working with package managers
- Using task runners to improve workflow
- Configuring Drupal for Twig debugging


## Gesso

Gesso is a [Sass](http://sass-lang.com/)-based starter theme that outputs accessible HTML5 markup. It uses a mobile-first responsive approach and leverages [SMACSS](https://smacss.com/) to organize styles as outlined in the [Drupal 8 CSS architecture guidelines](https://www.drupal.org/node/1887918). This encourages a component-based approach to theming through the creation of discrete, reusable UI elements. We can clone the `Gesso` repo to our `/web/theme/` folder by running the following command within the terminal window.


    cd web/themes
    git clone git@github.com:forumone/gesso.git gesso
    cd gesso

Since we are cloning the gesso theme into our git repo we will also want to remove the git file from `gesso` to avoid any issues. Within the terminal window, run the following command:


    rm -rf .git


## Pattern Lab

At its core, Pattern Lab is a static site generator (powered by either PHP or Node) that stitches together UI components. But there's a whole lot more to it than that as we will find out once we begin looking at components. We can install Pattern Lab directly into our theme using `composer` to create a Pattern Lab project by entering the following commands within our terminal window.


    composer create-project pattern-lab/edition-drupal-standard pattern-lab

If prompted, select `r` to overwrite existing `/source/` files.


## Forum One starter kit

When prompted, select `forumone/starterkit-twig-drupal-gesso` as the starterkit which is option 4. If prompted, select `r` to overwrite existing `/source/` files.


## NPM Packages

Next we will need to use `npm` to install any theme dependencies and packages that both our theme and Pattern Lab will need to build our assets. We can install packages by entering the following command within the terminal window.


    npm install


## Grunt

Finally we will need to build our assets by entering the following command within the terminal window.


    grunt gessoBuild


## Enabling Twig Debug

With our theme in place and Pattern Lab working, we now need to configure Drupal for local development. This generally involves modifying the `settings.php` file and creating `settings.local.php` and `local.services.yml` to allow for both disabled caching and to enable Twig debugging.

Anytime we manage settings files we will need to have the proper file permissions.  To make this process a little easier, we have already added the necessary `setting.local.php` and `local.services.yml` file.
