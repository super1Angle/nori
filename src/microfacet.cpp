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

#include <nori/bsdf.h>
#include <nori/frame.h>

NORI_NAMESPACE_BEGIN

class Microfacet : public BSDF {
public:
	Microfacet(const PropertyList &propList) {
		/* RMS surface roughness */
		m_alpha = propList.getFloat("alpha", 0.1f);

		/* Interior IOR (default: BK7 borosilicate optical glass) */
		m_intIOR = propList.getFloat("intIOR", 1.5046f);

		/* Exterior IOR (default: air) */
		m_extIOR = propList.getFloat("extIOR", 1.000277f);

		/* Albedo of the diffuse base material (a.k.a "kd") */
		m_kd = propList.getColor("kd", Color3f(0.5f));

		/* To ensure energy conservation, we must scale the 
		   specular component by 1-kd. 

		   While that is not a particularly realistic model of what 
		   happens in reality, this will greatly simplify the 
		   implementation. Please see the course staff if you're 
		   interested in implementing a more realistic version 
		   of this BRDF. */
		m_ks = 1 - m_kd.maxCoeff();
	}

	/// Evaluate the BRDF for the given pair of directions
	Color3f eval(const BSDFQueryRecord &bRec) const {
		throw NoriException("Uh oh -- Microfacet::eval() is not implemented!");
	}

	/// Evaluate the sampling density of \ref sample() wrt. solid angles
	float pdf(const BSDFQueryRecord &bRec) const {
		throw NoriException("Uh oh -- Microfacet::pdf() is not implemented!");
	}

	/// Sample the BRDF
	Color3f sample(BSDFQueryRecord &bRec, const Point2f &sample) const {
		throw NoriException("Uh oh -- Microfacet::sample() is not implemented!");
	}

	QString toString() const {
		return QString(
			"Microfacet[\n"
			"  alpha = %1,\n"
			"  intIOR = %2,\n"
			"  extIOR = %3,\n"
			"  kd = %4\n"
			"  ks = %5,\n"
			"]")
		.arg(m_alpha)
		.arg(m_intIOR)
		.arg(m_extIOR)
		.arg(m_kd.toString())
		.arg(m_ks);
	}
private:
	float m_alpha;
	float m_intIOR, m_extIOR;
	float m_ks;
	Color3f m_kd;
};

NORI_REGISTER_CLASS(Microfacet, "microfacet");
NORI_NAMESPACE_END
