# 05-Component Libraries

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

## Lesson Five: Component Libraries
The challenge with managing components in Pattern Lab and integrating them into Drupal is the fact that Drupal uses its own flavor of Twig which is evident by the extension of `*.html.twig`. This name spacing means that we cannot use simple Twig includes to pull in `*.twig` templates from Pattern Lab.

However we can overcome this challenge by enabling Twig name spacing and mapping out Pattern Lab folders located within our theme using the Component library module and our themes `*.info.yml` file.

### Topics covered
- Working with the Component Libraries module
- Enabling Twig Namespaces
- Using Includes, Extends and Embeds

## Working with the Component Libraries module
The Component Libraries module registers “component libraries” defined by our theme or module as Twig namespaces.  We already have this module downloaded as part of the branch.  We just need to navigate to http://pwc.dd:8083/admin/modules and enable the module.

## Enabling Twig Namespaces
Twig natively offers a feature called [“namespaced paths”](http://symfony.com/doc/current/cookbook/templating/namespaced_paths.html). Drupal core registers many Twig namespaces so that you can reference the Twig templates from specific modules or themes. For example, you may have seen this:

```
  {% extends "@classy/block/block--system-menu-block.html.twig" %}
```

The text, `@classy`, indicates the Twig namespace we wish to use when getting the twig template.

However, these same “namespaced” paths restrict us from including, extending or embedding Twig templates that Drupal does not recognize.

The Component Libraries module allows us to specify a different directory for our component library's Twig files and allows us to register a unique Twig namespace for those files.

We can add our new “namespace” by opening the pwc.info.yml file and adding the following metadata to the end of the file:

```
  component-libraries:
    base:
      paths:
        - pattern-lab/source/_patterns/00-base
    components:
      paths:
        - pattern-lab/source/_patterns/01-components
    layouts:
      paths:
        - pattern-lab/source/_patterns/02-layouts
    templates:
      paths:
        - pattern-lab/source/_patterns/03-templates
    pages:
      paths:
        - pattern-lab/source/_patterns/04-pages

```
- Save the file
- Clear Drupal’s cache to ensure our changes are picked up by the theme.

Now that we have Pattern Lab’s component paths registered with our theme we can begin modifying Drupal’s Twig templates to point to Pattern Lab and the components we created earlier. As we walk through these next steps, we will begin to see how this technique can be used to make Pattern Lab the canonical source for our markup.

## Using Includes, Extends and Embeds
While working in Pattern Lab we were introduced to the concept of `includes` which allowed us to render a Twig template inside another one.  We will use this same technique along with learning a few new ones to `extend` and `embed` Twig templates from Pattern Lab inside our Drupal templates.

**Lesson One: Header region**

If we browse to `/web/themes/pwc/templates/layout/` we will see a readme titled `region--header-pl.md` outlining each step involved in developing our Header region Twig template.

**Lesson Two: Main region**

If we browse to `/web/themes/pwc/templates/layout/` we will see a readme titled `region--content-pl.md` outlining each step involved in developing our Main content region Twig template.

**Lesson Three: Footer region**

If we browse to `/web/themes/pwc/templates/layout/` we will see a readme titled `region--footer-pl.md` outlining each step involved in developing our Footer region Twig template.

**Lesson Four: Site branding**

If we browse to `/web/themes/pwc/templates/block/` we will see a readme titled `block--system-branding-block-pl.md` outlining each step involved in developing our Site branding Twig template.

**Lesson Five: Main menu**

If we browse to `/web/themes/pwc/templates/navigation/` we will see a readme titled `menu--main-pl.md` outlining each step involved in developing our Main menu Twig template.

**Lesson Six: Footer menu**

If we browse to `/web/themes/pwc/templates/navigation/` we will see a readme titled `menu--footer-pl.md` outlining each step involved in developing our Footer menu Twig template.

**Lesson Seven: Hero**

If we browse to `/web/themes/pwc/templates/paragraph/` we will see a readme titled `paragraph--hero-pl.md` outlining each step involved in developing our Hero Twig template.

**Lesson Eight: Featured section**

If we browse to `/web/themes/pwc/templates/paragraph/` we will see a readme titled `paragraph--featured-species-pl.md` outlining each step involved in developing our Featured Twig template.

**Lesson Nine: News section**

If we browse to `/web/themes/pwc/templates/paragraph/` we will see a readme titled `paragraph--news-section-pl.md` outlining each step involved in developing our News section Twig template.

**Lesson Ten: Card**

If we browse to `/web/themes/pwc/templates/content/` we will see a readme titled `node--card-pl.md` outlining each step involved in developing our Card Twig template.

**Lesson Eleven: List**

If we browse to `/web/themes/pwc/templates/content/` we will see a readme titled `node--list-pl.md` outlining each step involved in developing our List Twig template.

**Lesson Twelve: Teaser**

If we browse to `/web/themes/pwc/templates/content/` we will see a readme titled `node--teaser-pl.md` outlining each step involved in developing our Teaser Twig template.

## Conclusion
Now that we have our Drupal templates pointing to Pattern Lab’s markup we have the flexibility of changing the markup in one location.  This technique ensures that we can reuse templates in a smart way that take into consideration components and best practices for theming.

In the final lesson we will take a look at an up and coming module called UI Patterns.
