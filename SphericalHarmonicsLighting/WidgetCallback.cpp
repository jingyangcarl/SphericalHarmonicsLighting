#include "Widget.h"

/*
Description:
	This function is used to process key events, which is a Qt event function
Intput:
	@ QKeyEvent* event: a key event;
Output:
	@ void returnValue: void;
*/
void Widget::keyPressEvent(QKeyEvent* event) {

	QVector<QVector3D> temp;

	// process the event
	switch (event->key()) {
	case Qt::Key_Left:
		skybox->loadPrev();
		break;
	case Qt::Key_Right:
		skybox->loadNext();
		break;
	case Qt::Key_Up:
		break;
	case Qt::Key_Down:
		break;
	case Qt::Key_0:
		camera = new Camera3D();
		camera->translate(QVector3D(0.0, 0.0, -35.0));
		break;
	}

	// update widget
	update();
}

/*
Description:
	This function is used to process mouse events, which is a Qt event function
Intput:
	@ QKeyEvent* event: a mouse event;
Output:
	@ void returnValue: void;
*/
void Widget::mousePressEvent(QMouseEvent* event) {
	// process the event
	if (event->buttons() == Qt::LeftButton)
		mousePosition = QVector2D(event->localPos());
	if (event->buttons() == Qt::RightButton)
		mousePosition = QVector2D(event->localPos());
	if (event->buttons() == Qt::MiddleButton)
		mousePosition = QVector2D(event->localPos());
	event->accept();

	// update widget
	update();
}

/*
Description:
	This function is used to process mouse move events, which is a Qt event function
Intput:
	@ QKeyEvent* event: a mouse move event;
Output:
	@ void returnValue: void;
*/
void Widget::mouseMoveEvent(QMouseEvent* event) {

	QVector2D diff = QVector2D(event->localPos()) - mousePosition;
	mousePosition = QVector2D(event->localPos());

	float angle = diff.length();
	QVector3D axis = QVector3D(diff.y(), diff.x(), 0.0f);

	// process the event
	if (event->buttons() == Qt::LeftButton) {
		camera->rotate(QQuaternion::fromAxisAndAngle(axis, angle));
	}
	if (event->buttons() == Qt::RightButton) {
		objects[objects.size() - 1]->rotate(QQuaternion::fromAxisAndAngle(axis, angle));
	}
	if (event->buttons() == Qt::MiddleButton) {
	}

	// update widget
	update();
}

/*
Description:
	This function is used to process wheel events, which is a Qt event function
Intput:
	@ QKeyEvent* event: a wheel event;
Output:
	@ void returnValue: void;
*/
void Widget::wheelEvent(QWheelEvent* event) {
	// process the event
	if (event->delta() > 0)
		camera->translate(QVector3D(0.0f, 0.0f, 3.0f));
	else if (event->delta() < 0)
		camera->translate(QVector3D(0.0f, 0.0f, -3.0f));

	// update widget
	update();
}

/*
Description:
	This function is used to process timer events, which is a Qt event function
Intput:
	@ QKeyEvent* event: a timer event;
Output:
	@ void returnValue: void;
*/
void Widget::timerEvent(QTimerEvent* event) {
	// process the event

	// for each cube 
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) {
			objects[i]->rotate(QQuaternion::fromAxisAndAngle(1.0, 0.0, 0.0, qSin(angleObject)));
			objects[i]->rotate(QQuaternion::fromAxisAndAngle(0.0, 1.0, 0.0, qCos(angleObject)));
		} else {
			objects[i]->rotate(QQuaternion::fromAxisAndAngle(0.0, 1.0, 0.0, qSin(angleObject)));
			objects[i]->rotate(QQuaternion::fromAxisAndAngle(1.0, 0.0, 0.0, qCos(angleObject)));
		}
	}

	// for group
	if (groups.size() < 1) {
		qDebug() << "Carl::Widget::timerEvent: error: group index out of bounds";
		exit(-1);
	}
	groups[0]->rotate(QQuaternion::fromAxisAndAngle(1.0, 0.0, 0.0, qCos(angleGroup)));
	groups[0]->rotate(QQuaternion::fromAxisAndAngle(0.0, 1.0, 0.0, -qCos(angleGroup)));

	// reverse
	angleObject += M_PI / 180.0f;
	angleGroup += M_PI / 360.0f;

	// update widget
	update();
}
