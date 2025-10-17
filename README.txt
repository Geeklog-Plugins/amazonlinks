=========================================================
 AmazonLinks Plugin for Geeklog
=========================================================

Authors: ::Ben - ben AT geeklog DOT fr
Version: 1.0
Compatible with: Geeklog 2.1.x and higher
License: GPL v2 or later
---------------------------------------------------------

DESCRIPTION
---------------------------------------------------------
AmazonLinks is a lightweight plugin for Geeklog that automatically adds
a list of Amazon affiliate links at the end of each article based on
keywords detected in the article body.

No database tables are created — the plugin works entirely from a
simple configuration file that you can customize.

It’s ideal for blogs, news, or review sites that want to display
contextual product links automatically.

---------------------------------------------------------
FEATURES
---------------------------------------------------------
- Automatically detects keywords in the article content.
- Displays a modern, responsive block of affiliate links under each story.
- Uses a configuration file (no database dependency).
- Supports Amazon affiliate tag tracking.
- Simple to install and remove via Geeklog’s plugin interface.
- Compatible with most Geeklog themes.

---------------------------------------------------------
INSTALLATION
---------------------------------------------------------
1. Copy the folder **amazonlinks/** into your Geeklog `/plugins/` directory.

2. Log in as an administrator, then go to:
   **Admin → Plugins → Install New Plugin → AmazonLinks**

   → The plugin supports automatic installation through the Geeklog
     plugin interface (no manual SQL or configuration steps required).

---------------------------------------------------------
CONFIGURATION
---------------------------------------------------------
After installation, you must configure the plugin using a dedicated
configuration file named:

   **amazonlinks_config.php**

This file is included with the plugin package in the folder:
   `/plugins/amazonlinks/`

You need to **move** this file manually to your **Geeklog data folder**, e.g.:

   `/path/to/geeklog/data/amazonlinks_config.php`

---------------------------------------------------------
EDITING THE CONFIGURATION FILE
---------------------------------------------------------
Open the file `amazonlinks_config.php` in a text editor and modify:

- `'title'` → the title displayed above the links (e.g. “🔗 Recommended Resources”)
- `'tag'` → your Amazon affiliate tag (optional, e.g. `mytag-20`)
- `'max_links'` → the maximum number of links to display (default: 5)
- `'keywords'` → the list of keyword–URL pairs that define which links
  are shown when a word is found in an article.

---------------------------------------------------------
TEMPLATE MODIFICATION
---------------------------------------------------------
To display the AmazonLinks block under your articles, you must edit
your theme’s story templates and add the variable where you want the
block to appear.

Typically, edit the following files in your theme folder:

   `/path/to/geeklog/layout/YOURTHEME/article/storytext.thtml`
   `/path/to/geeklog/layout/YOURTHEME/article/featuredstorytext.thtml`

Then add the following line near the end of each file, **just before
the closing `</div>` of the story body**:

{amazonlinks}


This placeholder will be automatically replaced by the plugin with
the list of recommended Amazon links.

---------------------------------------------------------
UNINSTALLATION
---------------------------------------------------------
To uninstall, go to:
**Admin → Plugins → AmazonLinks → Uninstall**

The plugin removes itself cleanly (no database entries or configuration data).

---------------------------------------------------------
SUPPORT & CONTRIBUTIONS
---------------------------------------------------------
For support, discussions, or updates:
https://www.geeklog.net/forum/

If you’d like to contribute improvements or translations, feel free
to share them with the Geeklog community.

---------------------------------------------------------
ENJOY!
---------------------------------------------------------
AmazonLinks lets you enrich your articles with relevant Amazon links,
automatically and without effort.
