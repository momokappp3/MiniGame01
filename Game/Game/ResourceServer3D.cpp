/*
** ���L���\�[�X�𐧌䂷�邽�߂̃T�[�o
*/

#include "DxLib.h"
#include "ResourceServer3D.h"
#include <vector>

namespace {
    // �ÓI�����o����
    std::unordered_map<std::string, int> _mapGraph;  //�t�@�C���� ���ʔԍ�
}

void ResourceServer3D::Init() {
    _mapGraph.clear();
}

void ResourceServer3D::Release() {   //�������ǂ����Ă���̂�
    ClearGraph();
}

void ResourceServer3D::ClearGraph() {

    // ���ׂẴf�[�^�̍폜������
    for (auto itr = _mapGraph.begin(); itr != _mapGraph.end(); itr++) {
        MV1DeleteModel(itr->second);   //�����ō폜���Ă���clear
    }
    _mapGraph.clear();
}

int ResourceServer3D::MV1LoadModel(const TCHAR* FileName) {

    // �L�[�̌���
    auto itr = _mapGraph.find(FileName);  //�����̃t�@�C�����̃L�[�̈ʒu

    if (itr != _mapGraph.end()) {   //�ŏI�v�f�̎��ł͂Ȃ�������@�@�����̐���

        // �L�[��������
        return itr->second;   //second = �n���h��
    }

    int cg = DxLib::MV1LoadModel(FileName);     // DXLIB��API���ĂԂ̂ŁA::��擪�ɕt���A���̃N���X�̓������O�̊֐��Ƌ�ʂ���
    // �L�[�ƃf�[�^��map�ɓo�^
    _mapGraph[FileName] = cg;

    return cg;   //���ʔԍ���Ԃ�
}

bool ResourceServer3D::DeleteModel(int handle) {

    if (handle == -1) {
        return false;
    }

    for (auto itr = _mapGraph.begin(); itr != _mapGraph.end(); itr++) {
        if (itr->second == handle) {
            DxLib::MV1DeleteModel(handle);

            _mapGraph.erase(itr);

            return true;
        }
    }

    return false;
}