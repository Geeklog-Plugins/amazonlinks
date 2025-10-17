<?php

/* Reminder: always indent with 4 spaces (no tabs). */
// +---------------------------------------------------------------------------+
// | AmazonLinks Plugin 1.0                                                    |
// +---------------------------------------------------------------------------+
// | functions.php                                                             |
// |                                                                           |
// | This file implements the Geeklog Plugin API functions and core logic      |
// | used by the AmazonLinks plugin. It handles keyword detection within       |
// | articles and automatic display of affiliate link blocks.                  |
// +---------------------------------------------------------------------------+
// | Copyright (C) 2025 by the following authors:                              |
// |                                                                           |
// | Authors: ::Ben - ben AT geeklog DOT fr                                    |
// +---------------------------------------------------------------------------+
// |                                                                           |
// | This program is free software; you can redistribute it and/or             |
// | modify it under the terms of the GNU General Public License               |
// | as published by the Free Software Foundation; either version 2            |
// | of the License, or (at your option) any later version.                    |
// |                                                                           |
// | This program is distributed in the hope that it will be useful,           |
// | but WITHOUT ANY WARRANTY; without even the implied warranty of            |
// | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             |
// | GNU General Public License for more details.                              |
// |                                                                           |
// | You should have received a copy of the GNU General Public License         |
// | along with this program; if not, write to the Free Software Foundation,   |
// | Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.           |
// |                                                                           |
// +---------------------------------------------------------------------------+

// functions.inc – AmazonLinks Plugin

if (strpos(strtolower($_SERVER['PHP_SELF']), 'functions.inc') !== false) {
    die('This file can not be used on its own.');
}

/**
 * Hook: Injects Amazon affiliate links as styled buttons below articles
 */
function plugin_templateSetVars_amazonlinks($templatename, $template)
{
    global $_CONF;

    // Apply only to story templates
    if (!in_array($templatename, array('storytext', 'featuredstorytext', 'storybodytext'))) {
        return;
    }

    $configFile = $_CONF['path_data'] . 'amazonlinks_config.php';
    if (!file_exists($configFile)) {
        return;
    }

    include $configFile;
    if (empty($AMAZONLINKS_CONF['keywords'])) {
        return;
    }

    $title    = isset($AMAZONLINKS_CONF['title']) ? $AMAZONLINKS_CONF['title'] : '🔗 Recommended Resources';
    $tag      = isset($AMAZONLINKS_CONF['tag']) ? trim($AMAZONLINKS_CONF['tag']) : '';
    $max      = isset($AMAZONLINKS_CONF['max_links']) ? intval($AMAZONLINKS_CONF['max_links']) : 5;
    $keywords = $AMAZONLINKS_CONF['keywords'];

    // Extract article content
    $content = strtolower(strip_tags($template->get_var('story_bodytext_only')));
    if (empty($content)) {
        return;
    }

    // Detect keywords in the article text
    $found = array();
    foreach ($keywords as $word => $data) {
        $url   = is_array($data) ? $data['url'] : $data;
        $label = is_array($data) && !empty($data['label']) ? $data['label'] : ucfirst($word);

        if (stripos($content, $word) !== false) {
            // Add affiliate tag if missing
            if ($tag && strpos($url, 'tag=') === false) {
                $sep = (strpos($url, '?') !== false) ? '&' : '?';
                $url .= $sep . 'tag=' . urlencode($tag);
            }
            $found[$label] = $url;
        }
    }

    if (empty($found)) {
        return;
    }

    // Limit the number of displayed links
    if (count($found) > $max) {
        $found = array_slice($found, 0, $max, true);
    }

    // Generate HTML output
    $html = '<style>
    .amazonlinks-block {
        margin-top: 2em;
        padding: 1em 0em;
        border-top: 1px solid #ddd;
    }
    .amazonlinks-title {
        font-weight: bold;
        margin-bottom: 0.6em;
    }
    .amazonlinks-list {
        display: flex;
        flex-wrap: wrap;
        gap: 0.6em;
    }
    .amazonlinks-btn {
        background-color: #0A66C2; /* LinkedIn blue */
        color: #fff; /* white text by default */
        text-decoration: none;
        padding: 0.6em 1.3em;
        border-radius: 6px;
        font-size: 0.9em;
        font-weight: 500;
        box-shadow: 0 2px 5px rgba(0,0,0,0.1);
        transition: all 0.2s ease-in-out;
    }
    .amazonlinks-btn:hover {
        background-color: #007BFF; /* lighter blue on hover */
        color: #fff !important;
        text-decoration: none;
        transform: translateY(-2px);
        box-shadow: 0 4px 8px rgba(0,0,0,0.15);
    }
    .amazonlinks-btn:visited {
        color: #fff;
    }
    </style>';

    $html .= '<div class="amazonlinks-block">';
    $html .= '<div class="amazonlinks-title">' . htmlspecialchars($title) . '</div>';
    $html .= '<div class="amazonlinks-list">';

    foreach ($found as $label => $url) {
        $html .= '<a class="amazonlinks-btn" href="' . htmlspecialchars($url) . '" target="_blank" rel="nofollow">'
            . htmlspecialchars($label) . '</a>';
    }

    $html .= '</div></div>';

    $template->set_var('amazonlinks', $html);
}

/**
 * Plugin initialization hook
 */
function plugin_init_amazonlinks()
{
    global $_CONF;
    return true;
}

/**
 * Automatic uninstall function for AmazonLinks
 *
 * @return array
 */
function plugin_autouninstall_amazonlinks()
{
    $out = array(
        // No database tables to remove
        'tables'      => array(),

        // Groups created during installation
        'groups'      => array('Amazon Links Admin'),

        // Associated features
        'features'    => array('amazonlinks.admin'),

        // No PHP blocks
        'php_blocks'  => array(),

        // No specific variables
        'vars'        => array()
    );

    return $out;
}

?>
