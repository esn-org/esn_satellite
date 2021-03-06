<?php
// $Id: views-view-fields.tpl.php,v 1.6 2008/09/24 22:48:21 merlinofchaos Exp $
/**
 * @file views-view-fields.tpl.php
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->separator: an optional separator that may appear before a field.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
<!-- <div class="wrapper-out">
    <div class="wrapper-in"  style="<?php if ($background) print "background: url('$background') no-repeat 0 0;"; ?> ">
      <h2><span class="title-outer"><span class="title-inner"><?php print t('In the Spotlight');?></span></span></h2>
      <div class="spotlight-content">
	      <?php foreach ($fields as $id => $field): ?>
	        <?php if (!empty($field->separator)): ?>
	          <?php print $field->separator; ?>
	        <?php endif; ?>
	      
	        <<?php print $field->inline_html;?> class="views-field-<?php print $field->class; ?>">
	          <?php if ($field->label): ?>
	            <label class="views-label-<?php print $field->class; ?>">
	              <?php print $field->label; ?>:
	            </label>
	          <?php endif; ?>
	            <?php
	            // $field->element_type is either SPAN or DIV depending upon whether or not
	            // the field is a 'block' element type or 'inline' element type.
	            ?>
	            <<?php print $field->element_type; ?> class="field-content"><?php print $field->content; ?></<?php print $field->element_type; ?>>
	        </<?php print $field->inline_html;?>>
	      <?php endforeach; ?>
      </div>
    </div>
</div> -->



<?php $background = $fields['field_image_fid']->content; ?>
<?php unset($fields['field_image_fid']); ?>
<?php unset($fields['field_text_spotlight_value']); ?>

		<div class="spotlight-content" style="<?php if ($background) print "background: url('$background') no-repeat 0 0;"; ?>">
			<h2 class="spotlight"><span class="title-outer"><span class="title-inner"><?php print t('In the Spotlight');?></span></span></h2>
			<div class="black-div">
				<div class="black-div-inner">
					<?php foreach ($fields as $id => $field): ?>
						<?php if (!empty($field->separator)): ?>
							<?php print $field->separator; ?>
						<?php endif; ?>

						<<?php print $field->inline_html;?> class="views-field-<?php print $field->class; ?>">
						<?php if ($field->label): ?>
							<label class="views-label-<?php print $field->class; ?>">
								<?php print $field->label; ?>:
							</label>
						<?php endif; ?>
						<?php
						// $field->element_type is either SPAN or DIV depending upon whether or not
						// the field is a 'block' element type or 'inline' element type.
						?>
						<?php print $field->content; ?>
						</<?php print $field->inline_html;?>>
					<?php endforeach; ?>
				</div>
			</div>
		</div>




