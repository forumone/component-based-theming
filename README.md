# 03-Components

# Component-based Theming with Twig

This repository is for using a Composer based workflow with Drupal 8.  We will be using this repository and the branches to maintain various snapshots as we progress thru each lesson.

## Assumptions

This training assumes that you are already running Acquia Dev Desktop and have a familiarity with installing Drupal using the standard means of downloading, setting up a database, configuring a localhost, and completing the browser-based install. In the [Master](https://github.com/forumone/component-based-theming/tree/master#component-based-theming-with-twig) repo, we walked through quickly installing **Acquia Dev Desktop**, **Terminal**, **Composer**, **Node & NPM**, **Grunt**, and **Git**. Ensure that you have a working AMP stack and are comfortable working within the command-line interface using a Terminal window before continuing.

## Lesson Three: Building Components

Reviewing a design we will work thru identifying the components that make up the page and begin building our first components.  Utilizing PatternLab we will first build our component using simple markup, styling, and Twig.  We will learn how to then combine components using advanced Twig syntax to build a completed page.

**Topics covered**

- Creating components
- Managing components within Pattern Lab
- Using layouts within Pattern Lab
- Understanding Templates and Pages


## Creating Components

Anytime we begin the process of building components, we must first visualize the design by reviewing the creative files and mapping out how a specific section is built, any commonalities and what if anything can be reused.

Let’s begin with reviewing the [Homepage](https://codepen.io/cchumley/full/KvpoqV/) design that we will be working with.


## Managing components with Pattern Lab

The basic building blocks of a component start with three files.  First is the `*.twig` file that contains our basic markup.  Second is the `*.scss` file that contains our styling.  Third is the `*.yml` file that contains any data attributes that we want to pass to our markup.

We will explore the following page design and discuss how each component is developed and how to iterate on each component to make it more robust by taking advantage of Twig variables to replace static content with dynamic content.

### Header

- Site branding
- Main Menu

### Hero

### Featured

- Card

### Updates

- Listing

### New Species

- Teaser

### Footer

- Site branding
- Footer menu


## Using Layouts within Pattern Lab

### Header

### Featured

### Updates

### Releases

### Footer


## Understanding Templates & Pages

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
