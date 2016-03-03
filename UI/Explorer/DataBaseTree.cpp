/*
 * DataBaseTree.cpp
 *
 *  Created on: Mar 3, 2016
 *      Author: stephane
 */

#include <UI/Explorer/DataBaseTree.h>
#include <QSortFilterProxyModel>
#include <QDebug>
#include <QModelIndexList>
#include <UI/Explorer/Model/TableFilterProxyModel.h>

namespace UI {
namespace Explorer {

DataBaseTree::DataBaseTree(QWidget *parent) : QTreeView(parent) {

	this->dataBaseModel = new Model::DataBaseModel();

	Model::TableFilterProxyModel *filter = new Model::TableFilterProxyModel();
	filter->setSourceModel(this->dataBaseModel);

	this->setModel(filter);
	this->setHeaderHidden(true);
	this->expandToDepth(0);
}

void DataBaseTree::filterTable(QString text)
{
	((Model::TableFilterProxyModel *)this->model())->setFilterRegExp(text);
}


DataBaseTree::~DataBaseTree() {
	// TODO Auto-generated destructor stub
}

} /* namespace Explorer */
} /* namespace UI */