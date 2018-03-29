#ifndef LINK_PROPERTY_H
#define LINK_PROPERTY_H
#include <QtCore>
#include <boost/shared_ptr.hpp>
#include <qttreepropertybrowser.h>
#include <qtvariantproperty.h>
#include <urdf_editor/common.h>
#include <urdf_editor/joint_property.h>
#include <urdf_model/link.h>

namespace urdf_editor
{
  class LinkGeometryProperty : public QObject
  {
    Q_OBJECT
  public:
    LinkGeometryProperty(urdf::GeometrySharedPtr geometry);
    ~LinkGeometryProperty();

    void loadFactoryForManager(boost::shared_ptr<QtTreePropertyBrowser> property_editor);

    void loadData();

    QtProperty *getTopItem() { return top_item_; }

  private slots:
    void linkGeometryValueChanged(QtProperty *property, const QVariant &val);

  private:
    urdf::GeometrySharedPtr geometry_;
    QtVariantPropertyManager *manager_;
    QtVariantEditorFactory *factory_;
    QtProperty *top_item_;
    bool loading_;
  };

  class LinkCollisionProperty : public QObject
  {
    Q_OBJECT
  public:
    LinkCollisionProperty(urdf::CollisionSharedPtr collision);
    ~LinkCollisionProperty();

    void loadFactoryForManager(boost::shared_ptr<QtTreePropertyBrowser> property_editor);

    void loadData();

    QtProperty *getTopItem() { return top_item_; }

  private slots:
    void linkCollisionValueChanged(QtProperty *property, const QVariant &val);

  private:
    urdf::CollisionSharedPtr collision_;
    QtVariantPropertyManager *manager_;
    QtVariantEditorFactory *factory_;
    QtProperty *top_item_;
    bool loading_;
    boost::shared_ptr<OriginProperty> origin_property_;
    boost::shared_ptr<LinkGeometryProperty> geometry_property_;

  };

  class LinkNewMaterialProperty : public QObject
  {
    Q_OBJECT
  public:
    LinkNewMaterialProperty(urdf::MaterialSharedPtr material);
    ~LinkNewMaterialProperty();

    void loadFactoryForManager(boost::shared_ptr<QtTreePropertyBrowser> property_editor);

    void loadData();

    QtProperty *getTopItem() { return top_item_; }

  private slots:
    void linkNewMaterialValueChanged(QtProperty *property, const QVariant &val);

  private:
    urdf::MaterialSharedPtr material_;
    QtVariantPropertyManager *manager_;
    QtVariantEditorFactory *factory_;
    QtProperty *top_item_;
    bool loading_;

  };

  class LinkVisualProperty : public QObject
  {
    Q_OBJECT
  public:
    LinkVisualProperty(urdf::VisualSharedPtr visual);
    ~LinkVisualProperty();

    void loadFactoryForManager(boost::shared_ptr<QtTreePropertyBrowser> property_editor);

    void loadData();

    QtProperty *getTopItem() { return top_item_; }

  private slots:
    void linkVisualValueChanged(QtProperty *property, const QVariant &val);

  private:
    urdf::VisualSharedPtr visual_;
    QtVariantPropertyManager *manager_;
    QtVariantEditorFactory *factory_;
    QtProperty *top_item_;
    bool loading_;
    boost::shared_ptr<OriginProperty> origin_property_;
    boost::shared_ptr<LinkNewMaterialProperty> new_material_property_;
    boost::shared_ptr<LinkGeometryProperty> geometry_property_;

  };

  class LinkInertialProperty : public QObject
  {
    Q_OBJECT
  public:
    LinkInertialProperty(urdf::InertialSharedPtr inertial);
    ~LinkInertialProperty();

    void loadFactoryForManager(boost::shared_ptr<QtTreePropertyBrowser> property_editor);

    void loadData();

    QtProperty *getTopItem() { return top_item_; }

  private slots:
    void linkInertialValueChanged(QtProperty *property, const QVariant &val);

  private:
    urdf::InertialSharedPtr inertial_;
    QtVariantPropertyManager *manager_;
    QtVariantEditorFactory *factory_;
    QtProperty *top_item_;
    bool loading_;
    boost::shared_ptr<OriginProperty> origin_property_;

  };

  class LinkProperty : public QObject
  {
    Q_OBJECT
  public:
    LinkProperty(urdf::LinkSharedPtr link);
    ~LinkProperty();

    void loadProperty(boost::shared_ptr<QtTreePropertyBrowser> property_editor);

    void loadData();

  private slots:
    void linkValueChanged(QtProperty *property, const QVariant &val);

  signals:
    void linkNameChanged(LinkProperty *property, const QVariant &val);

  private:
    urdf::LinkSharedPtr link_;
    QtVariantPropertyManager *manager_;
    QtVariantEditorFactory *factory_;
    QtProperty *top_item_;
    bool loading_;
    boost::shared_ptr<LinkInertialProperty> inertial_property_;
    boost::shared_ptr<LinkVisualProperty> visual_property_; // this needs to be array since multiple visuals models are allowed.
    boost::shared_ptr<LinkCollisionProperty> collision_property_; // this needs to be array since multiple collisions models are allowed.
    QtVariantProperty *name_item_;

  };
  typedef boost::shared_ptr<LinkProperty> LinkPropertyPtr;
}
#endif // LINK_TREE_PROPERTY_H
