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
- Activating Gesso
- Previewing Pattern Lab


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

Using an editor of your choice, navigate to the `/web/sites/default/` folder and open the file named `local.services.yml`.  Locate the section of code commented with **Enable Twig debugging** and change the `debug: false` value to `debug:  true`.

Next within a terminal window change into the the `/web/` root of our Drupal project and flush the cache by entering the following command:


    drush cr

Now that we have rebuilt Drupal’s cache our environment will display Twig comments needed for locating Twig files and any File name suggestions that we can use.

## Activating Gesso

In order to preview the Gesso theme along with Twig comments we need to enable and set Gesso as our Default theme within the Drupal UI.

Begin by navigating to http://pwc.dd:8083/admin/appearance and locate the Gesso theme within the **Uninstalled Themes** section of the UI and follow these steps to activate it:


- Select the Install and set as default link next to the Gesso theme
- Navigate back to http://pwc.dd:8083/ and confirm Gesso is now active
- Inspect the page and confirm that Twig is now displaying **FILE NAME SUGGESTIONS**

With Gesso now active we can move on to previewing the Pattern Lab instance for our theme.

## Previewing Pattern Lab

Earlier we used Composer to create an instance of Pattern Lab that is confined within our theme. To verify that Pattern Lab is functioning properly we can navigate directly to Pattern Lab within our browser by going to the following url: http://pwc.dd:8083/themes/gesso/pattern-lab/public/

We will be working with Pattern Lab extensively throughout the remaining training.  While we are previewing the default out of the box version of Pattern Lab we will see in our next lesson how we can configure it to work with our Base styling, building components, layouts, templates and pages.

----------
## Notes:

If you checked out this branch prior to following the steps above then a majority of these steps will already have been performed.  In order to build Pattern Lab and compile any assets needed for the Gesso theme you will need to perform the following command line steps within the terminal:


    cd /web/themes/gesso
    npm install
    grunt gessoBuild

Once Pattern Lab and all assets have been processed you can activate the theme if it has not already been done for you and then simply refresh your browser and the theme will display properly.

If you are familiar with Configuration management in Drupal you can also perform the following command line steps within the terminal to ensure any database changes are synched up properly:


    cd /web
    drush cim -y

Finally to have a complete snapshot of lesson two prior to checking out the next lesson you can also perform a database import using the `pwc.sql` file located in the `/db/` folder.
