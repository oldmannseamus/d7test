<?php

/** 
 * @file
 * Administration page callbacks for the annotate module.
 */

/**
 * Form builder. Configure annotateions.
 *
 * @ingroup form
 * @see system_settings_form()
 */

function annotate_admin_settings(){
	// Get an array of node types with internal names as key and
	// "friendly names" as values. E.g.,
	// array('page' => 'Basic Page', 'article' => 'Articles')

	$types = node_type_get_types();
	foreach($types as $node_type){
		$options[$node_type->type] = $node_type->name;
	}
	$form['annotate_node_types'] = array(
		'#type' => 'checkboxes',
		'#title' => t('Users may annotate these content type'),
		'#options' => $options,
		'#default_value' => variable_get('annotate_node_types', array('page')),
		'#description' => t('A text field will be available on these content types to make user-specific notes.'),
	);

	$form['#submit'][] = 'annotate_admin_settings_submit';
	return system_settings_form($form);
}