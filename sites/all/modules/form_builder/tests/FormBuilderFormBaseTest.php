<?php

class FormBuilderFormBaseTest_LoaderMockup {
  public function getElement($form_type, $form_type, $element_type, FormBuilderFormInterface $form, &$element) {
    return new FormBuilderElementBase($this, array(), $form, $element);
  }
}

class FormBuilderFormBaseTest extends DrupalUnitTestCase {

  public static function getInfo() {
    return array(
      'name' => 'FormBuilderFormBase unit tests.',
      'description' => 'Tests form element handling.',
      'group' => 'Form builder',
    );
  }

  protected function emptyForm() {
    $loader = new FormBuilderFormBaseTest_LoaderMockup();
    return new FormBuilderFormBase($loader, 'webform', 'test', NULL, array(), array(), NULL);
  }

  /**
   * @covers FormBuilderFormBase::setElementArray
   * @covers FormBuilderFormBase::getElement
   * @covers FormBuilderFormBase::getElementArray
   * @covers FormBuilderFormBase::getFormArray
   * @covers FormBuilderFormBase::addDefaults
   * @covers FormBuilderFormBase::createElements
   * @covers FormBuilderFormNode::insertChild
   */
  public function testSetElementArray() {
    $form = $this->emptyForm();
    $a['#form_builder']['element_id'] = 'A';
    $a['#key'] = 'a';
    $a['#type'] = 'textfield';
    $this->assertEqual('A', $form->setElementArray($a)->getId());
    $rform = $form->getFormArray();
    $this->assertArrayHasKey('a', $rform);

    $a['#key'] = 'x';
    $this->assertEqual('A', $form->setElementArray($a)->getId());
    $rform = $form->getFormArray();
    $this->assertArrayNotHasKey('a', $rform);
    $this->assertArrayHasKey('x', $rform);

    $b['#key'] = 'b';
    $b['#type'] = 'textfield';
    $b['#form_builder'] = array('element_id' => 'B', 'parent_id' => 'A');
    $this->assertEqual('B', $form->setElementArray($b)->getId());
    $this->assertArrayNotHasKey('b', $form->getFormArray());
    $this->assertArrayHasKey('b', $form->getElementArray('A'));

    $b['#form_builder']['parent_id'] = 'NON EXISTING';
    $this->assertFalse($form->setElementArray($b));
    $this->assertArrayHasKey('b', $form->getElementArray('A'));

    $b['#form_builder']['parent_id'] = FORM_BUILDER_ROOT;
    $this->assertEqual('B', $form->setElementArray($b)->getId());
    $this->assertArrayHasKey('b', $form->getFormArray());
    $this->assertArrayNotHasKey('b', $form->getElementArray('A'));
  }

  /**
   * @covers FormBuilderFormBase::addDefaults
   * @covers FormBuilderFormBase::createElements
   * @covers FormBuilderFormNode::insertChild
   * @covers FormBuilderFormNode::setParent
   * @covers FormBuilderFormNode::getChildren
   */
  public function test_setElementArray_nestedElement() {
    $form = $this->emptyForm();
    $element = array('#type' => 'textfield', '#title' => 'Test', '#key' => 'test');
    $element['child'] = array('#key' => 'a', '#type' => 'textfield');
    $element['child']['#form_builder']['element_id'] = 'A';
    $obj = $form->setElementArray($element);
    $this->assertInstanceOf('FormBuilderFormApiNode', $obj);
    $this->assertArrayHasKey('test', $form->getFormArray());
    $this->assertCount(1, $obj->getChildren());
  }

  /**
   * @covers FormBuilderFormBase::getElementIds
   * @covers FormBuilderFormBase::unsetElement
   * @covers FormBuilderFormBase::unindexElements
   * @covers FormBuilderFormNode::removeChild
   */
  public function test_unsetElementArray() {
    $form['a']['#type'] = 'textfield';
    $form['a']['#form_builder'] = array('element_id' => 'A');
    $form['a']['b'] = array('#type' => 'textfield');
    $form['a']['b']['#form_builder'] = array('element_id' => 'B');
    $loader = new FormBuilderFormBaseTest_LoaderMockup();
    $form_obj =  new FormBuilderFormBase($loader, 'webform', 'test', NULL, array(), $form);
    $this->assertEqual(array('A', 'B'), $form_obj->getElementIds());
    $form_obj->unsetElement('A');
    $this->assertEqual(array(), $form_obj->getElementIds());
  }

  /**
   * @covers FormBuilderFormBase::__construct
   * @covers FormBuilderFormBase::indexElements
   */
  public function testElementIndexing() {
    $form['a']['#type'] = 'textfield';
    $form['a']['#form_builder'] = array('element_id' => 'A');
    $form['a']['b'] = array('#type' => 'textfield');
    $form['a']['b']['#form_builder'] = array('element_id' => 'B');
    $loader = new FormBuilderFormBaseTest_LoaderMockup();
    $form_obj = new FormBuilderFormBase($loader, 'webform', 'test', NULL, array(), $form);
    $this->assertNotEmpty($form_obj->getElementArray('A'));
    $this->assertNotEmpty($form_obj->getElementArray('B'));
  }

  /**
   * Integration test _form_builder_add_element().
   *
   * @covers ::_form_builder_add_element
   * @covers ::form_builder_field_render
   * @covers FormBuilderFormNode::formParents
   * @covers FormBuilderFormBase::load
   * @covers FormBuilderFormBase::save
   * @covers FormBuilderFormBase::serialize
   * @covers FormBuilderFormBase::unserialize
   */
  public function test_form_builder_add_element() {
    module_load_include('inc', 'form_builder', 'includes/form_builder.admin');
    $loader = FormBuilderLoader::instance();
    $form = $loader->getForm('webform', 'test', 'test', array());
    $form->save();
    $data = _form_builder_add_element('webform', 'test', 'email', NULL, 'test', TRUE);
    $this->assertNotEmpty($data);
    $this->assertNotEmpty($data['html']);
  }
}
