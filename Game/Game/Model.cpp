#include "Model.h"
#include"ResourceServer.h"

Model::Model() : ObjectBase() {
	_handle = -1;
}

Model::~Model() {
}

bool Model::Load(const TCHAR* fileName) {

	_handle = ResourceServer::MV1LoadModel(fileName);

	return _handle != -1;
}

void Model::Process() {

	if (_handle == -1) {
		return;
	}

	_transform.Update();

	MV1SetMatrix(_handle, _transform.GetTransform());
}

void Model::Render() {

	if (_handle == -1) {
		return;
	}

	MV1DrawModel(_handle);
}

