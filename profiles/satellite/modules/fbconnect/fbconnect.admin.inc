<?php
// $Id: fbconnect.admin.inc,v 1.9 2009/02/27 17:46:09 lanets Exp $

/** 
 * @file 
 * Administration page callbacks for the fbconnect module. 
 */ 

/** 
 * Form builder. Configure fbconnect. 
 * 
 * @ingroup forms
 * @see system_settings_form(). 
 */
function fbconnect_admin_settings() {
  global $base_url;
  $form['api'] = array(
    '#type' => 'fieldset',
    '#title' => t('Facebook connect config'),
    '#collapsible' => FALSE,
    '#weight' => -5,
  );
  $form['api']['fbconnect_api_key'] = array( 
    '#type' => 'textfield', 
    '#title' => t('Facebook API KEY'), 
    '#default_value' => variable_get('fbconnect_api_key', NULL), 
  );   
  $form['api']['fbconnect_secret_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook Secret API KEY'),
    '#default_value' => variable_get('fbconnect_secret_api_key', NULL),
  ); 
  $form['api']['fbconnect_invitef_content'] = array(
    '#type' => 'textfield',
    '#title' => t('Invite message'),      
    '#default_value' => variable_get('fbconnect_invitef_content', t('Enjoy facebook connect module')),
  );
  $form['api']['fbconnect_invitef_type'] = array(
    '#type' => 'textfield',
    '#title' => t('Your site name'),      
    '#default_value' => variable_get('fbconnect_invitef_type', variable_get('site_name', NULL)),
  );
  
  $form['api']['fbconnect_invitef_redirect'] = array(
    '#type' => 'textfield',
    '#title' => t('Redirect url, when user valid or skip invite friend form'),
    '#default_value' => variable_get('fbconnect_invitef_redirect', $base_url),
  );
   
  $module_path = drupal_get_path('module', 'fbconnect') .'/images/';
  $button = array(
    'small_short'  => theme_image($module_path .'Connect_white_small_short.gif'),
    'medium_short' => theme_image($module_path .'Connect_white_medium_short.gif'),
    'medium_long'  => theme_image($module_path .'Connect_white_medium_long.gif'),
    'large_short'  => theme_image($module_path .'Connect_white_large_short.gif'),
    'large_long'   => theme_image($module_path .'Connect_white_large_long.gif'),
  );
  $form['api']['fbconnect_button_type'] = array(
    '#type' => 'radios',
    '#default_value' => variable_get('fbconnect_button_type', 'large_long'),
    '#options' => $button,
  );
  $form['api']['fbconnect_reg_feed'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display story feed prompt after user registration'),
    '#default_value' => variable_get('fbconnect_reg_feed', array('fbconnect_reg_feed')),
  );
  $form['api']['fbconnect_com_feed'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display story feed prompt after comment post'),      
    '#default_value' => variable_get('fbconnect_com_feed', array('fbconnect_com_feed')),
  );
  $form['api']['fbconnect_reg_feed_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Registration feed bundle ID'),
    '#default_value' => variable_get('fbconnect_reg_feed_id', FBCONNECT_REG_FEED_BUNDLEID),
  );
  $form['api']['fbconnect_com_feed_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Comment feed bundle ID'),
    '#default_value' => variable_get('fbconnect_com_feed_id', FBCONNECT_COMMENT_FEED_BUNDLEID),
  );

  return system_settings_form($form);
}