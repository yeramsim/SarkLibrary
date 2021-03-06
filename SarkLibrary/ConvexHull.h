#ifndef __CONVEX_HULL__
#define __CONVEX_HULL__

#include <vector>
#include "core.h"
#include "ACollider.h"
#include "primitives.hpp"

namespace sark {

	// convex hull.
	// it can be generated by convex hull builder.
	class ConvexHull : public ACollider {
	public:
		typedef std::vector<Vector3> PointSet;
		typedef std::vector<TriangleFace16> FaceSet;
		typedef std::vector<TriangleFace16>::const_iterator FaceIterator;

	private:
		// point set of object space convex hull.
		PointSet mPoints;

		// transformed point set.
		PointSet mTransPoints;

		// triangle face set. it can be empty.
		FaceSet mFaces;

	public:
		ConvexHull(ASceneComponent* reference);

		ConvexHull(ASceneComponent* reference,
			const PointSet& points);

		ConvexHull(ASceneComponent* reference,
			const PointSet& points,
			const FaceSet& faces);

		~ConvexHull();

		// get original(not transformed) point set.
		const PointSet& GetPointSet() const;

		// get transformed point set.
		const PointSet& GetTransPointSet() const;

		// get triangle face set.
		const FaceSet& GetFaceSet() const;

		// get type
		const Type GetType() const override;

		// intersection test with given collider.
		// *note: it does not generate any collision
		// informations then just test the intersection.
		bool IntersectWith(const ACollider* coll) const override;

		// update convex hull.
		void Update() override;
	};

}
#endif