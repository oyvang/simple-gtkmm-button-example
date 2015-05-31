#include <iostream>
#include <gtkmm.h>

class HelloWorld : public Gtk::Window {
public:
  HelloWorld();
  virtual ~HelloWorld();

protected: 
  //Signal handlers:     
  void on_button_clicked(); 
  //Member widgets: 
  Gtk::Button m_button;    
private:
 int counter = 0;
};

int main (int argc, char *argv[]) {
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
  HelloWorld helloworld;
  //Shows the window and returns when it is closed.
  return app->run(helloworld);
}

HelloWorld::HelloWorld()
  : m_button("Hello World") { //lable button
  // Window border width
  set_border_width(10);
  // Signal handler
  m_button.signal_clicked().connect(sigc::mem_fun(*this,
              &HelloWorld::on_button_clicked));
  //Add button to window
  add(m_button);
  // Shows the widget
  m_button.show();
}
HelloWorld::~HelloWorld() {
}

void HelloWorld::on_button_clicked() {
  counter++;
  if(counter > 3) {
    std::cout << "Bye, bye!" << std::endl;
    hide();
  }else{
    std::cout << "Hello World" << std::endl;
  }
}
