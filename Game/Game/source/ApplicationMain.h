#include "appframe.h"

class ApplicationMain : public ApplicationBase {
	//typedef ApplicationBase base;  //cのやり方　名前をつけている
	using base = ApplicationBase;  //c++
public:
	bool Initialize(HINSTANCE hInstance) override;
	bool Terminate() override;
	bool Input() override;
	bool Process() override;
	bool Render() override;

	bool AppWindowed() override {
#ifdef _DEBUG  //デバッグビルド
		return true; 
#else   //リリースビルド
		return false;
#endif
	}
	int DispSizeW() override { return 1280; }
	int DispSizeH() override { return 720; }

protected:
}; 
