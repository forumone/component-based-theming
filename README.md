# 03-Components

# Component-based Theming with Twig
This repository is for using a Composer based workflow with Drupal 8.  We will be using this repository and its branches to maintain various snapshots as we progress thru each lesson.

## Assumptions
This training assumes that you are already running Acquia Dev Desktop and have a familiarity with installing Drupal using the standard means of downloading, setting up a database, configuring a localhost, and completing the browser-based install. In the [Master](https://github.com/forumone/component-based-theming/tree/master#component-based-theming-with-twig) branch, we walked through quickly installing **Acquia Dev Desktop**, **Terminal**, **Composer**, **Node & NPM**, **Grunt**, and **Git**. Ensure that you have a working AMP stack and are comfortable working within the command-line interface using a Terminal window before continuing.

**Notes**
If you checked out this branch prior to following the steps in the previous lesson and want to make sure your environment is up to date, then follow the steps detailed below.

Open a terminal window and run the following commands:

```
  cd /web/themes/gesso
  npm install
  grunt gessoBuild
```

Once Pattern Lab and all assets have been processed, activate the Gesso theme (if its not already active) and then refresh your browser and the theme will display properly.

If you are familiar with configuration management in Drupal you can also run the following commands to ensure any database changes are synched up properly:

```
  cd /web
  drush cim -y
```

Finally, to have a complete snapshot of this lesson prior to checking out the next lesson you can also perform a database import using the `pwc.sql` file located in the `/db/` folder.

## Lesson Three: Building Components
In this lesson we will be reviewing a design, identifying the components that make up the page, and discussing how those components can be created and managed using Pattern Lab.  

Each folder we will be working in contains a readme that details the steps involved in creating the particular component, layout, template or page.

There is also a **lessons** folder that contains the final versions of the files we will be creating and working with that you can refer to or use to complete the project.

**Topics covered**

- Creating components
- Managing components within Pattern Lab
- Using layouts within Pattern Lab
- Understanding Templates and Pages

## Creating Components
When building components it helps to review the design and begin mapping out how a specific component is built, any commonalities between components, how a component will be used and if a component can be modified to create a variant.

Let’s begin with reviewing the [Homepage](https://codepen.io/cchumley/full/KvpoqV/) design that we will be working with.

If we take a look at our homepage design we can break our page layout into several regions with each region containing one or more components.

[**Header**](https://codepen.io/cchumley/full/zdGWwz/)

- [Site name](https://codepen.io/cchumley/pres/JydLWO)
- [Nav Main](https://codepen.io/cchumley/pres/prJLeg)

[**Main**](https://codepen.io/cchumley/full/YxXaVO/)

- [**Hero**](https://codepen.io/cchumley/pres/EvjENX)
- **Section**
  - [Card](https://codepen.io/cchumley/pres/wqamzb)
- **Section**
  - [Listing](https://codepen.io/cchumley/pres/NvqYdK)
  - [Teaser](https://codepen.io/cchumley/pres/VzLXpd)

[**Footer**](https://codepen.io/cchumley/full/jLPzmP/)

- [Site name](https://codepen.io/cchumley/pres/JydLWO)
- [Nav Footer](https://codepen.io/cchumley/pres/rzVdjj)

We will concentrate on creating each individual component and then learn how to use various Twig syntax to create more advanced components.  From there we will move on to working with  layouts within Pattern Lab  to combine components that make more functional sections.

A new theme titled **PWC (Pacific Whale Conservancy)** has already been created for us which we will be using for managing our Pattern Lab instance.  We can find the new theme located at `/web/themes/pwc` and we will be working within the `/web/themes/pwc/pattern-lab/source/_patterns/` folder.

## Managing components with Pattern Lab
The basic building blocks of a component start with three files.  While not all 3 files are required to create a component, we need to at least start with a `*.twig` file that contains our basic markup and a `*.scss` file that contains component specific `CSS`.

> To ensure that our components are consistently styled each component folder has already been created for us with the required Sass file that accompanies the component we will be building.

Finally we can utilize pattern-specific data for each component by adding a  `*.yml` file that contains data that can be pass to our component.

**Lesson One: Button component**

If we browse to `/web/themes/pwc/pattern-lab/source/_patterns/01-components/button/` we will see a folder that will contain the `_button.scss` partial along with a `readme` outlining each step that we will be following in developing our Button component.

**Lesson Two: Card component**

If we browse to `/web/themes/pwc/pattern-lab/source/_patterns/01-components/card/` we will see a folder that will contain the `_card.scss` partial along with a `readme` outlining each step that we will be following in developing our Card component.

**Lesson Three: Hero component**

If we browse to `/web/themes/pwc/pattern-lab/source/_patterns/01-components/hero/` we will see a folder that will contain the `_hero.scss` partial along with a `readme` outlining each step that we will be following in developing our Hero component.

**Lesson Four: Listing component**

If we browse to `/web/themes/pwc/pattern-lab/source/_patterns/01-components/listing/` we will see a folder that will contain the `_listing.scss` partial along with a `readme` outlining each step that we will be following in developing our Listing component.

**Lesson Five: Nav Footer component**

If we browse to `/web/themes/pwc/pattern-lab/source/_patterns/01-components/nav-footer/` we will see a folder that will contain the `_nav-footer.scss` partial along with a `readme` outlining each step that we will be following in developing our Nav Footer component.

**Lesson Six: Nav Main component**

If we browse to `/web/themes/pwc/pattern-lab/source/_patterns/01-components/nav-main/` we will see a folder that will contain the `_nav-main.scss` partial along with a `readme` outlining each step that we will be following in developing our Nav Main component.

**Lesson Seven: Site name component**

If we browse to `/web/themes/pwc/pattern-lab/source/_patterns/01-components/site-name/` we will see a folder that will contain the `_site-name.scss` partial along with a `readme` outlining each step that we will be following in developing our Site name component.

**Lesson Eight: Teaser component**

If we browse to `/web/themes/pwc/pattern-lab/source/_patterns/01-components/teaser/` we will see a folder that will contain the `_teaser.scss` partial along with a `readme` outlining each step that we will be following in developing our Teaser component.

## Using Layouts within Pattern Lab
Now that we have each component created we can learn how to build layouts in Pattern Lab that will take advantage of Twig Includes to render each component.  Our Homepage is broken down into three different layouts, Header, Main and Footer.

**Lesson Nine: Header layout**

If we browse to `/web/themes/pwc/pattern-lab/source/_patterns/02-layouts/header/` we will see a folder that will contain the `_header.scss` partial along with a `readme` outlining each step that we will be following in developing our Header layout.

**Lesson Ten: Main layout**

If we browse to `/web/themes/pwc/pattern-lab/source/_patterns/02-layouts/main/` we will see a folder that will contain the `_main.scss` partial along with a `readme` outlining each step that we will be following in developing our Main layout.

**Lesson Eleven: Footer layout**

If we browse to `/web/themes/pwc/pattern-lab/source/_patterns/02-layouts/footer/` we will see a folder that will contain the `_footer.scss` partial along with a `readme` outlining each step that we will be following in developing our Footer layout.

## Understanding Templates & Pages
Templates and Pages are very similar in Pattern Lab and are often confused.  However a Template is used to peace together various layouts to form page-level objects.  Templates provide context for relatively abstract components.  Whereas Pages are specific instances of Templates.

**Lesson Twelve: Homepage template**

If we browse to `/web/themes/pwc/pattern-lab/source/_patterns/03-templates/` we will see a a `readme` outlining each step that we will be following in developing our Homepage template.

**Lesson Thirteen: Homepage page**

If we browse to `/web/themes/pwc/pattern-lab/source/_patterns/04-pages/` we will see a a `readme` outlining each step that we will be following in developing our Homepage page.

## Conclusion
We have successfully converted our Homepage design into a fully functioning Homepage in Pattern Lab using various techniques to develop components, layouts, templates and pages.  In the next section we will take a look at how to integrate Pattern Lab with Drupal 8.
