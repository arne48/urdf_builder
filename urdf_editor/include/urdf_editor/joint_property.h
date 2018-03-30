#ifndef JOINT_PROPERTY
#define JOINT_PROPERTY
//#include <QtCore>
#include <boost/shared_container_iterator.hpp>
#include <qttreepropertybrowser.h>
#include <qtvariantproperty.h>
#include <urdf_editor/common.h>
#include <urdf_model/joint.h>

namespace urdf_editor
{
  class OriginProperty : public QObject
  {
    Q_OBJECT
  public:
    OriginProperty(urdf::Pose &origin);
    ~OriginProperty();

    void loadFactoryForManager(boost::shared_ptr<QtTreePropertyBrowser> property_editor);

    void loadData();

    QtProperty *getTopItem() { return top_item_; }

  private slots:
    void originValueChanged(QtProperty *property, const QVariant &val);

  private:
    urdf::Pose &origin_;
    QtVariantPropertyManager *manager_;
    QtVariantEditorFactory *factory_;
    QtProperty *top_item_;
    bool loading_;

  };

  class JointAxisProperty : public QObject
  {
    Q_OBJECT
  public:
    JointAxisProperty(urdf::Vector3 &axis);
    ~JointAxisProperty();

    void loadFactoryForManager(boost::shared_ptr<QtTreePropertyBrowser> property_editor);

    void loadData();

    QtProperty *getTopItem() { return top_item_; }

  private slots:
    void jointAxisValueChanged(QtProperty *property, const QVariant &val);

  private:
    urdf::Vector3 &axis_;
    QtVariantPropertyManager *manager_;
    QtVariantEditorFactory *factory_;
    QtProperty *top_item_;
    bool loading_;

  };

  class JointSafetyProperty : public QObject
  {
    Q_OBJECT
  public:
    JointSafetyProperty(urdf::JointSafetySharedPtr safety);
    ~JointSafetyProperty();

    void loadFactoryForManager(boost::shared_ptr<QtTreePropertyBrowser> property_editor);

    void loadData();

    QtProperty *getTopItem() { return top_item_; }

  private slots:
    void jointSafetyValueChanged(QtProperty *property, const QVariant &val);

  private:
    urdf::JointSafetySharedPtr safety_;
    QtVariantPropertyManager *manager_;
    QtVariantEditorFactory *factory_;
    QtProperty *top_item_;
    bool loading_;

  };

  class JointMimicProperty : public QObject
  {
    Q_OBJECT
  public:
    JointMimicProperty(urdf::JointMimicSharedPtr mimic, QStringList &joint_names);
    ~JointMimicProperty();

    void loadFactoryForManager(boost::shared_ptr<QtTreePropertyBrowser> property_editor);

    void loadData();

    QtProperty *getTopItem() { return top_item_; }

  private slots:
    void jointMimicValueChanged(QtProperty *property, const QVariant &val);

  private:
    urdf::JointMimicSharedPtr mimic_;
    QtVariantPropertyManager *manager_;
    QtVariantEditorFactory *factory_;
    QtProperty *top_item_;
    bool loading_;
    QStringList &joint_names_;

  };

  class JointCalibrationProperty : public QObject
  {
    Q_OBJECT
  public:
    JointCalibrationProperty(urdf::JointCalibrationSharedPtr calibration);
    ~JointCalibrationProperty();

    void loadFactoryForManager(boost::shared_ptr<QtTreePropertyBrowser> property_editor);

    void loadData();

    QtProperty *getTopItem() { return top_item_; }

  private slots:
    void jointCalibrationValueChanged(QtProperty *property, const QVariant &val);

  private:
    urdf::JointCalibrationSharedPtr calibration_;
    QtVariantPropertyManager *manager_;
    QtVariantEditorFactory *factory_;
    QtProperty *top_item_;
    bool loading_;

  };

  class JointDynamicsProperty : public QObject
  {
    Q_OBJECT
  public:
    JointDynamicsProperty(urdf::JointDynamicsSharedPtr dynamics);
    ~JointDynamicsProperty();

    void loadFactoryForManager(boost::shared_ptr<QtTreePropertyBrowser> property_editor);

    void loadData();

    QtProperty *getTopItem() { return top_item_; }

  private slots:
    void jointDynamicsValueChanged(QtProperty *property, const QVariant &val);

  private:
    urdf::JointDynamicsSharedPtr dynamics_;
    QtVariantPropertyManager *manager_;
    QtVariantEditorFactory *factory_;
    QtProperty *top_item_;
    bool loading_;

  };

  class JointLimitsProperty : public QObject
  {
    Q_OBJECT
  public:
    JointLimitsProperty(urdf::JointLimitsSharedPtr limits);
    ~JointLimitsProperty();

    void loadFactoryForManager(boost::shared_ptr<QtTreePropertyBrowser> property_editor);

    void loadData();

    QtProperty *getTopItem() { return top_item_; }

  private slots:
    void jointLimitsValueChanged(QtProperty *property, const QVariant &val);

  private:
    urdf::JointLimitsSharedPtr limits_;
    QtVariantPropertyManager *manager_;
    QtVariantEditorFactory *factory_;
    QtProperty *top_item_;
    bool loading_;

  };


  class JointProperty : public QObject
  {
    Q_OBJECT
  public:
    JointProperty(urdf::JointSharedPtr joint, QStringList &link_names, QStringList &joint_names);
    ~JointProperty();

    void loadProperty(boost::shared_ptr<QtTreePropertyBrowser> property_editor);

    void loadData();

  private slots:
    void jointValueChanged(QtProperty *property, const QVariant &val);

  signals:
    void jointNameChanged(JointProperty *property, const QVariant &val);

  private:
    urdf::JointSharedPtr joint_;
    QtVariantPropertyManager *manager_;
    QtVariantEditorFactory *factory_;
    bool loading_;
    QStringList &link_names_;
    QStringList &joint_names_;
    boost::shared_ptr<urdf_editor::JointLimitsProperty> limits_property_;
    boost::shared_ptr<urdf_editor::JointDynamicsProperty> dynamics_property_;
    boost::shared_ptr<urdf_editor::JointCalibrationProperty> calibration_property_;
    boost::shared_ptr<urdf_editor::JointMimicProperty> mimic_property_;
    boost::shared_ptr<urdf_editor::JointSafetyProperty> safety_property_;
    boost::shared_ptr<urdf_editor::JointAxisProperty> axis_property_;
    boost::shared_ptr<urdf_editor::OriginProperty> origin_property_;
    QtVariantProperty *name_item_;
    QtVariantProperty *type_item_;
    QtVariantProperty *parent_item_;
    QtVariantProperty *child_item_;

  };
  typedef boost::shared_ptr<JointProperty> JointPropertyPtr;
}
#endif // JOINT_PROPERTY

