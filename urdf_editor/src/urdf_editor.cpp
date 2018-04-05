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

  rviz_panel_ = new rviz::RenderPanel();
  auto rviz_layout = new QVBoxLayout(ui->mainTabWidget->currentWidget());
  rviz_layout->setMargin(0);
  rviz_layout->addWidget(rviz_panel_);


  rviz_manager_ = new rviz::VisualizationManager( rviz_panel_ );
  rviz_panel_->initialize( rviz_manager_->getSceneManager(), rviz_manager_ );
  rviz_manager_->initialize();
  rviz_manager_->startUpdate();

  rviz_manager_->setFixedFrame("base_link");

  //Original loads from "robot_description"
  rviz::Display *original_robot_model_display = rviz_manager_->createDisplay("rviz/RobotModel", "Original Robot Model", true);
  original_robot_model_display->setEnabled(true);

  //Modified loads from "urdf_editor/modified_robot_description"
  rviz::Display *modified_robot_model_display = rviz_manager_->createDisplay("rviz/RobotModel", "Modified Robot Model", true);
  modified_robot_model_display->setEnabled(true);

  //Once a parameter is changed the urdf is regenerated and "urdf_editor/modified_robot_description" is updated
  urdf_tree_.reset(new urdf_editor::URDFProperty(ui->robotTreeWidget, ui->propertyBrowserContainer));

  //Load from parameter server
  std::string model;
  ros::param::param<std::string>("robot_description", model, "");
  urdf_tree_->loadURDF(model);

  //Or load from file
  //TODO
  QString file_path = "/home/user/xiaomi_gen1.urdf";
}

URDFEditor::~URDFEditor()
{
  delete ui;
}


