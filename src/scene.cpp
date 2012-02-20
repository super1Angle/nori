/*
    This file is part of Nori, a simple educational ray tracer

    Copyright (c) 2012 by Wenzel Jakob and Steve Marschner.

    Nori is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License Version 3
    as published by the Free Software Foundation.

    Nori is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <nori/scene.h>
#include <nori/bitmap.h>

NORI_NAMESPACE_BEGIN

Scene::Scene(const PropertyList &) {
}

Scene::~Scene() {
}

void Scene::activate() {
	m_kdtree.build();
}

void Scene::addChild(NoriObject *obj) {
	switch (obj->getClassType()) {
		case EMesh:
			m_kdtree.addMesh(static_cast<Mesh *>(obj));
			break;

		default:
			throw NoriException(QString("Scene::addChild(<%1>) is not supported!").arg(
				classTypeName(obj->getClassType())));
	}
}

	
QString Scene::toString() const {
	return QString("Scene[]");
}

NORI_REGISTER_CLASS(Scene, "scene");
NORI_NAMESPACE_END
