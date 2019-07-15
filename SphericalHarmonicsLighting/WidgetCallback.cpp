#include "Widget.h"

void Widget::keyPressEvent(QKeyEvent* event) {

	QVector<QVector3D> temp;

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
	case Qt::Key_1:
		//groups[0]->delObject(camera);
		//groups[1]->delObject(camera);
		//groups[0]->addObject(camera);
		break;
	case Qt::Key_2:
		//groups[0]->delObject(camera);
		//groups[1]->delObject(camera);
		//groups[1]->addObject(camera);
		break;
	}
	update();
}

void Widget::mousePressEvent(QMouseEvent* event) {
	if (event->buttons() == Qt::LeftButton)
		mousePosition = QVector2D(event->localPos());
	if (event->buttons() == Qt::RightButton)
		mousePosition = QVector2D(event->localPos());
	event->accept();
	update();
}

void Widget::mouseMoveEvent(QMouseEvent* event) {

	QVector2D diff = QVector2D(event->localPos()) - mousePosition;
	mousePosition = QVector2D(event->localPos());

	float angle = diff.length();
	QVector3D axis = QVector3D(diff.y(), diff.x(), 0.0f);

	if (event->buttons() == Qt::LeftButton) {
		camera->rotate(QQuaternion::fromAxisAndAngle(axis, angle));
	}
	if (event->buttons() == Qt::RightButton) {
		objects[0]->rotate(QQuaternion::fromAxisAndAngle(axis, angle));
	}
	update();
}

void Widget::wheelEvent(QWheelEvent* event) {
	if (event->delta() > 0)
		camera->translate(QVector3D(0.0f, 0.0f, 3.0f));
	else if (event->delta() < 0)
		camera->translate(QVector3D(0.0f, 0.0f, -3.0f));
	update();
}

void Widget::timerEvent(QTimerEvent* event) {
	// for each star 
	//for (int i = 1; i < 9; i++) {
	//	if (i % 2 == 0) {
	//		objects[i]->rotate(QQuaternion::fromAxisAndAngle(1.0, 0.0, 0.0, qSin(angleObject)));
	//		objects[i]->rotate(QQuaternion::fromAxisAndAngle(0.0, 1.0, 0.0, qCos(angleObject)));
	//	} else {
	//		objects[i]->rotate(QQuaternion::fromAxisAndAngle(0.0, 1.0, 0.0, qSin(angleObject)));
	//		objects[i]->rotate(QQuaternion::fromAxisAndAngle(1.0, 0.0, 0.0, qCos(angleObject)));
	//	}
	//}

	//// for star group
	//if (groups.size() < 1) {
	//	qDebug() << "Carl::Widget::timerEvent: error: group index out of bounds";
	//	exit(-1);
	//}
	//groups[1]->rotate(QQuaternion::fromAxisAndAngle(1.0, 0.0, 0.0, qCos(angleGroup)));
	//groups[1]->rotate(QQuaternion::fromAxisAndAngle(0.0, 1.0, 0.0, -qCos(angleGroup)));

	//// reverse
	//angleObject += M_PI / 180.0f;
	//angleGroup += M_PI / 360.0f;

	//update();
}
