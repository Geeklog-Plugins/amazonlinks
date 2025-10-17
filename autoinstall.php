<?php

/* Reminder: always indent with 4 spaces (no tabs). */
// +---------------------------------------------------------------------------+
// | AmazonLinks Plugin 1.0                                                    |
// +---------------------------------------------------------------------------+
// | autoinstall.php                                                           |
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

function plugin_autoinstall_amazonlinks($pi_name)
{
    $pi_name         = 'amazonlinks';
    $pi_display_name = 'Amazon Links';
    $pi_admin        = $pi_display_name . ' Admin';

    $info = array(
        'pi_name'         => $pi_name,
        'pi_display_name' => $pi_display_name,
        'pi_version'      => '1.0.0',
        'pi_gl_version'   => '2.1.1',
        'pi_homepage'     => 'https://geeklog.fr'
    );

    $groups = array(
        $pi_admin => 'Users in this group can administer the ' . $pi_display_name . ' plugin'
    );

    $features = array(
        $pi_name . '.admin' => 'Full access to ' . $pi_display_name
    );

    $mappings = array(
        $pi_name . '.admin' => array($pi_admin)
    );

    $tables = array();

    return array(
        'info'     => $info,
        'groups'   => $groups,
        'features' => $features,
        'mappings' => $mappings,
        'tables'   => $tables
    );
}

function plugin_postinstall_amazonlinks($pi_name)
{
    return true;
}

function plugin_compatible_with_this_version_amazonlinks($pi_name)
{
    if (!function_exists('COM_newTemplate')) return false;
    return true;
}
?>
