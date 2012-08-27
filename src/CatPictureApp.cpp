#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CatPictureApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void prepareSettings(Settings *settings);
	void update();
	void draw();
  private:
	float brightness1;
	float brightness2;
	float brightness3;
	int count;
};

void CatPictureApp::setup()
{
	brightness1 = 0.0f;
	brightness2 = 0.5f;
	brightness3 = 0.2f;
	count = 0;
}

void CatPictureApp::mouseDown( MouseEvent event )
{
}

void CatPictureApp::update()
{
	if(count < 50){
		brightness1 += 0.01f;
		brightness2 += 0.02f;
		brightness3 += 0.03f;
		count++;
	}
	else if(count>=50 && count<200){
		brightness1 = Rand::randFloat(0.0f,1.0f);
		brightness2 = Rand::randFloat(0.0f,1.0f);
		brightness3 = Rand::randFloat(0.0f,1.0f);
		count++;
	}
	else{
		brightness1 = 0.0f;
		brightness2 = 0.5f;
		brightness3 = 0.2f;
		count = 0;
	}
	
}

void CatPictureApp::prepareSettings(Settings *settings){
	settings -> setWindowSize(412,412);
}

void CatPictureApp::draw()
{
	gl::clear(Color(brightness1,brightness2,brightness3));
}

CINDER_APP_BASIC( CatPictureApp, RendererGl )
