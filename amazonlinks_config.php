<?php
// +--------------------------------------------------------------------------+
// | AmazonLinks Plugin Configuration File                                    |
// +--------------------------------------------------------------------------+
// | Example configuration file for the Geeklog AmazonLinks plugin.          |
// | Edit this file to match your website’s content and your Amazon tag.     |
// +--------------------------------------------------------------------------+

if (strpos(strtolower($_SERVER['PHP_SELF']), 'amazonlinks_config.php') !== false) {
    die('This file cannot be used on its own.');
}

$AMAZONLINKS_CONF = array(

    // Title displayed above the recommended links block
    'title'     => '🔗 Recommended Resources',

    // Your Amazon affiliate tag (optional)
    // Example: 'mytag-20' for Amazon.com
    'tag'       => 'exampletag-20',

    // Maximum number of links shown per article
    'max_links' => 5,

    // ----------------------------------------------------------------------
    // List of keywords mapped to product searches or URLs
    // ----------------------------------------------------------------------
    'keywords' => array(

        'windows'     => array('label' => 'Optimize Your PC', 'url' => 'https://www.amazon.com/s?k=windows+optimization+tools'),
        'mac'         => array('label' => 'Top Mac Applications', 'url' => 'https://www.amazon.com/s?k=mac+software'),
        'linux'       => array('label' => 'Best Linux Tools', 'url' => 'https://www.amazon.com/s?k=linux+open+source+software'),
        'office'      => array('label' => 'Office Productivity Tools', 'url' => 'https://www.amazon.com/s?k=office+software'),
        'antivirus'   => array('label' => 'Protect Your Computer', 'url' => 'https://www.amazon.com/s?k=antivirus+software'),
        'vpn'         => array('label' => 'Secure Your Connection', 'url' => 'https://www.amazon.com/s?k=vpn+for+windows'),
        'photo'       => array('label' => 'Edit Your Photos Easily', 'url' => 'https://www.amazon.com/s?k=photo+editing+software'),
        'video'       => array('label' => 'Video Editing Software', 'url' => 'https://www.amazon.com/s?k=video+editing+software'),
        'pdf'         => array('label' => 'Edit and Merge PDFs', 'url' => 'https://www.amazon.com/s?k=pdf+editor'),
        'productivity'=> array('label' => 'Boost Your Productivity', 'url' => 'https://www.amazon.com/s?k=productivity+tools')

    )
);
