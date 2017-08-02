# 04-Integrating Components

# Component-based Theming with Twig
This repository is for using a Composer based workflow with Drupal 8.  We will be using this repository and its branches to maintain various snapshots as we progress thru each lesson.

## Assumptions
This training assumes that you are already running Acquia Dev Desktop and have a familiarity with installing Drupal using the standard means of downloading, setting up a database, configuring a localhost, and completing the browser-based install. In the [Master](https://github.com/forumone/component-based-theming/tree/master#component-based-theming-with-twig) branch, we walked through quickly installing **Acquia Dev Desktop**, **Terminal**, **Composer**, **Node & NPM**, **Grunt**, and **Git**. Ensure that you have a working AMP stack and are comfortable working within the command-line interface using a Terminal window before continuing.

**Notes**
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

## Lesson Four: Integrating Components
In this lesson we will be working with Drupal 8 Twig templates and walking through how to integrate Pattern Lab within a Drupal 8 Theme.

The lessons folder contains a readme that details the steps involved in creating block, content, region, navigation, paragraph and view templates that will resemble those that we have in Pattern Lab.

**Topics covered**

- Creating Twig Templates
- Integrating Pattern Lab components
- Working with Entity Reference fields
- Using Twig Tweak and Twig Field Value modules

**Lesson One: Header region**

If we browse to `/web/themes/pwc/templates/layout/` we will see a readme titled `region``--``header.md` outlining each step involved in developing our Header region Twig template.

**Lesson Two: Main region**

If we browse to `/web/themes/pwc/templates/layout/` we will see a readme titled `region``--``content.md` outlining each step involved in developing our Main content region Twig template.

**Lesson Three: Footer region**

If we browse to `/web/themes/pwc/templates/layout/` we will see a readme titled `region--footer.md` outlining each step involved in developing our Footer region Twig template.

**Lesson Four: Site branding**

If we browse to `/web/themes/pwc/templates/block/` we will see a readme titled `block--system-branding-block.md` outlining each step involved in developing our Site branding Twig template.

**Lesson Five: Main menu**

If we browse to `/web/themes/pwc/templates/navigation/` we will see a readme titled `menu--main.md` outlining each step involved in developing our Main menu Twig template.

**Lesson Six: Footer menu**

If we browse to `/web/themes/pwc/templates/navigation/` we will see a readme titled `menu--footer.md` outlining each step involved in developing our Footer menu Twig template.

**Lesson Seven: Hero**

If we browse to `/web/themes/pwc/templates/paragraph/` we will see a readme titled `paragraph--hero.md` outlining each step involved in developing our Hero Twig template.

**Lesson Eight: Featured section**

If we browse to `/web/themes/pwc/templates/paragraph/` we will see a readme titled `paragraph--featured-species.md` outlining each step involved in developing our Featured Twig template.

**Lesson Nine: News section**

If we browse to `/web/themes/pwc/templates/paragraph/` we will see a readme titled `paragraph--news-section.md` outlining each step involved in developing our News section Twig template.

**Lesson Ten: Card**

If we browse to `/web/themes/pwc/templates/content/` we will see a readme titled `node--card.md` outlining each step involved in developing our Card Twig template.

**Lesson Eleven: List**

If we browse to `/web/themes/pwc/templates/content/` we will see a readme titled `node--list.md` outlining each step involved in developing our List Twig template.

**Lesson Twelve: Teaser**

If we browse to `/web/themes/pwc/templates/content/` we will see a readme titled `node--teaser.md` outlining each step involved in developing our Teaser Twig template.

## Conclusion
We have successfully integrated our Pattern Lab components into Drupal 8.  If we compare our theme side-by-side with Pattern Lab, they should look identical.  However, what happens when we need to make a change to a component?  We would have to make a change in two different places.  That’s hardly ideal, so in the next lesson we will take a look at how to use Component Libraries with Pattern Lab and Drupal 8 to make Pattern Lab our canonical source for our markup.
