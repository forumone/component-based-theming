# 06-UI Patterns

# Component-based Theming with Twig
This repository is for using a Composer based workflow with Drupal 8.  We will be using this repository and its branches to maintain various snapshots as we progress thru each lesson.

## Assumptions
This training assumes that you are already running Acquia Dev Desktop and have a familiarity with installing Drupal using the standard means of downloading, setting up a database, configuring a localhost, and completing the browser-based install. In the [Master](https://github.com/forumone/component-based-theming/tree/master#component-based-theming-with-twig) branch, we walked through quickly installing **Acquia Dev Desktop**, **Terminal**, **Composer**, **Node & NPM**, **Grunt**, and **Git**. Ensure that you have a working AMP stack and are comfortable working within the command-line interface using a Terminal window before continuing.

### Notes
If you checked out this branch prior to following the steps in the previous lesson and want to make sure your environment is up to date then follow the steps detailed below.

Open a terminal window and execute the following commands:

```
  cd /web/themes/gesso
  npm install
  grunt gessoBuild
```

Once Pattern Lab and all assets have been processed, you can activate the theme if it has not already been done for you and then simply refresh your browser and the theme will display properly.

If you are familiar with Configuration management in Drupal you can also run the following commands to ensure any database changes are synched up properly:

```
  cd /web
  drush cim -y
```

Finally, to have a complete snapshot of this lesson prior to checking out the next lesson you can also perform a database import using the `pwc.sql` file located in the `/db/` folder.

## Lesson Six: UI Patterns
As designs evolve, so will the tools required to elegantly implement them within Drupal.  In this lesson we’ll take a look at some of the more advanced components and how to tackle them.  We’ll also take a peek at the new UI Pattern Library module and how it integrates with Field Formatters and Display suite.

**Topics covered**

- Working with UI Patterns module
- Creating UI Patterns
- Using Pattern Lab with UI Patterns

## Working with UI Patterns module
## Creating UI Patterns
## Using Pattern Lab with UI Patterns
