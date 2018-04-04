#include <urdf_editor/urdf_editor.h>
#include "ui_industrial_robot_builder.h"
#include <rviz/visualization_manager.h>
#include <rviz/render_panel.h>
#include <rviz/default_plugin/robot_model_display.h>
#include <sstream>

URDFEditor::URDFEditor(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::URDFEditor)
{
  ui->setupUi(this);
//  rviz::RenderPanel *test;
//  test = new rviz::RenderPanel();
//  rviz_ = new urdf_editor::MyRviz(parent);
//  Construct and lay out render panel.
  rviz_panel_ = new rviz::RenderPanel();
  auto rviz_layout = new QVBoxLayout(ui->mainTabWidget->currentWidget());
  rviz_layout->setMargin(0);
  rviz_layout->addWidget(rviz_panel_);

//  // Next we initialize the main RViz classes.
//  //
//  // The VisualizationManager is the container for Display objects,
//  // holds the main Ogre scene, holds the ViewController, etc.  It is
//  // very central and we will probably need one in every usage of
//  // librviz.
  rviz_manager_ = new rviz::VisualizationManager( rviz_panel_ );
  rviz_panel_->initialize( rviz_manager_->getSceneManager(), rviz_manager_ );
  rviz_manager_->initialize();
  rviz_manager_->startUpdate();

  rviz_manager_->setFixedFrame("base_link");
  rviz::Display* robot_model_display;
  robot_model_display = rviz_manager_->createDisplay("rviz/RobotModel", "Robot Model", true);
  robot_model_display->setEnabled(true);


  QString file_path = "/home/user/xiaomi_gen1.urdf";

  urdf_tree_.reset(new urdf_editor::URDFProperty(ui->robotTreeWidget, ui->propertyBrowserContainer));

  std::string model;
  ros::param::param<std::string>("robot_description", model, "");
  urdf_tree_->loadURDF(model);
}

URDFEditor::~URDFEditor()
{
  delete ui;
}


