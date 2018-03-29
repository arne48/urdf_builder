#include <urdf_editor/urdf_editor.h>
#include <QApplication>

int main(int argc, char *argv[])
{
  std::cout<<"Start"<<std::endl;
  QApplication a(argc, argv);
  std::cout<<"Q done"<<std::endl;
  URDFEditor w;
  w.show();

  return a.exec();
}
