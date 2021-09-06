#pragma once

#include<QLabel>
#include<QWidget>
#include<QDebug>

class super_label : public QLabel
{
public:
	super_label(QWidget* parent);

public slots:
	void setVal(int val);
};

