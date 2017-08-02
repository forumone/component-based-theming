# 02-Tools

# Component-based Theming with Twig
This repository is part of a training on using a Composer based workflow with Drupal 8.  We will be using this repository and its branches to maintain various snapshots as we progress thru each lesson.

## Assumptions
This training assumes that you are already running Acquia Dev Desktop and have a familiarity with installing Drupal using the standard means of downloading, setting up a database, configuring a localhost, and completing the browser-based install. In the [Master](https://github.com/forumone/component-based-theming/tree/master#component-based-theming-with-twig) branch, we walked through quickly installing **Acquia Dev Desktop**, **Terminal**, **Composer**, **Node & NPM**, **Grunt**, and **Git**. Ensure that you have a working AMP stack and are comfortable working within the command-line interface using a Terminal window before continuing.

## Lesson Two: Tools
The title front-end developer now involves much more than just someone who writes HTML, CSS, and JavaScript.  We now use tools such as Composer, Pattern Lab, NPM and Grunt to help us work smarter when creating a theme in Drupal.  We’ll be using the Sass-based Gesso starter theme and it’s Pattern Lab starter kit as our starting point in creating our first components.

**Topics covered**

- Working with the Gesso theme
- Using Composer to create a Pattern Lab project
- Choosing a Pattern Lab starter kit
- Working with package managers
- Using task runners to improve workflow
- Configuring Drupal for Twig debugging
- Activating Gesso
- Previewing Pattern Lab


## Gesso
Gesso is a [Sass](http://sass-lang.com/)-based starter theme that outputs accessible HTML5 markup. It uses a mobile-first responsive approach and leverages [SMACSS](https://smacss.com/) to organize styles as outlined in the [Drupal 8 CSS architecture guidelines](https://www.drupal.org/node/1887918). This encourages a component-based approach to theming through the creation of discrete, reusable UI elements. We can clone the `Gesso` repo to our `/web/theme/` folder by running the following command within the terminal window.

```
  cd web/themes
  git clone git@github.com:forumone/gesso.git gesso
  cd gesso
```

Since we are cloning the gesso theme inside our git repo we will also want to remove the git file from `gesso` to avoid any issues. Within the terminal window, run the following command from the `/gesso` directory:

```
  rm -rf .git
```

## Pattern Lab
At its core, Pattern Lab is a static site generator (powered by either PHP or Node) that stitches together UI components. But there's a whole lot more to it than that, as we will find out once we begin looking at components. We can install Pattern Lab in our theme folder using `composer` to create a Pattern Lab project by running the following command from the /gesso theme folder.

```
  composer create-project pattern-lab/edition-drupal-standard pattern-lab
```

If prompted, select `r` to overwrite existing `/source/` files.

## Gesso starter kit
When prompted, select `forumone/starterkit-twig-drupal-gesso` as the starterkit (option 4 in the list). If prompted, select `r` to overwrite existing `/source/` files.

## NPM Packages
Next we will need to use `npm` to install any theme dependencies and packages that Gesso and Pattern Lab may need to build our assets. We can install packages by running the following command from the `/gesso` theme directory.

```
  npm install
```

## Grunt
Finally we will need to build our assets by running the following command.

```
  grunt gessoBuild
```

## Enabling Twig Debug
With our theme in place and Pattern Lab working, we now need to configure Drupal for local development. This generally involves modifying the `settings.php` file and creating `settings.local.php` and `local.services.yml` to disable caching and enable Twig debugging.

Any time we edit settings files we need to have the proper file permissions.  To make this process a little easier, we have already included a  `setting.local.php` and `local.services.yml` file in the repository.

Using an editor of your choice, navigate to the `/web/sites/default/` folder and open the file `local.services.yml`.  Locate the section of code commented with **Enable Twig debugging** and change the `debug: false` value to `debug: true`.

Next, from your terminal window, move to the the `/web/` root of our Drupal project and flush the cache by entering the following command:

```
  drush cr
```

Now that we have rebuilt Drupal’s cache, our environment will display Twig comments and file name suggestions when inspecting the source code.

## Activating Gesso
In order to preview the Gesso theme we need to enable and set Gesso as our default theme within the Drupal UI.

Begin by navigating to http://pwc.dd:8083/admin/appearance and locate the Gesso theme within the **Uninstalled Themes** section of the UI and follow these steps to activate it:

- Click the **Install and set as default link** next to the Gesso theme
- Navigate back to http://pwc.dd:8083/ and confirm Gesso is now active
- Inspect the page and confirm that Twig is now displaying **FILE NAME SUGGESTIONS**

With Gesso now active, we can move on to previewing Pattern Lab.

## Previewing Pattern Lab
Earlier we used Composer to create an instance of Pattern Lab within our theme. To verify that Pattern Lab is functioning properly, we can view Pattern Lab directly within our browser by going to the following url: http://pwc.dd:8083/themes/gesso/pattern-lab/public/

We will be working with Pattern Lab extensively throughout the remainder of the training.

## Notes:
If you checked out this branch prior to following the steps above, then a majority of these steps will already have been performed.  In order to build Pattern Lab and compile any assets needed for the Gesso theme you will need to run the following commands:

```
  cd /web/themes/gesso
  npm install
  grunt gessoBuild
```

Once Pattern Lab and all assets have been processed, you can activate the theme if it has not already been done for you and then simply refresh your browser and the theme will display properly.

If you are familiar with configuration management in Drupal you can also run the following commands to ensure any database changes are synched up properly:

```
  cd /web
  drush cim -y
```

Finally, to have a complete snapshot of this lesson prior to checking out the next lesson you can also perform a database import using the `pwc.sql` file located in the `/db/` folder.
