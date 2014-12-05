/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2003
*
*	File:	Node.h
*
******************************************************************/

#ifndef _CX3D_NODE_H_
#define _CX3D_NODE_H_

#include <iostream>
#include <fstream>
#include <assert.h>

#include <cybergarage/x3d/CyberX3DConfig.h>

#include <cybergarage/x3d/Vector.h>
#include <cybergarage/x3d/Field.h>
#include <cybergarage/x3d/StringUtil.h>
#include <cybergarage/x3d/LinkedList.h>
#include <cybergarage/x3d/JNode.h>

#include <cybergarage/x3d/NodeType.h>
#include <cybergarage/x3d/NodeString.h>

namespace CyberX3D
{

	class	SceneGraph;
	
	class	SFMatrix;
	
	class	AnchorNode;
	class	AppearanceNode;
	class	AudioClipNode;
	class	BackgroundNode;
	class	BillboardNode;
	class	BoxNode;
	class	CollisionNode;
	class	ColorNode;
	class	ColorInterpolatorNode;
	class	ConeNode;
	class	CoordinateNode;
	class	CoordinateInterpolatorNode;
	class	CylinderNode;
	class	CylinderSensorNode;
	class	DirectionalLightNode;
	class	ElevationGridNode;
	class	ExtrusionNode;
	class	FogNode;
	class	FontStyleNode;
	class	GroupNode;
	class	ImageTextureNode;
	class	IndexedFaceSetNode;
	class	IndexedLineSetNode;
	class	InlineNode;
	class	LODNode;
	class	MaterialNode;
	class	MovieTextureNode;
	class	NavigationInfoNode;
	class	NormalNode;
	class	NormalInterpolatorNode;
	class	OrientationInterpolatorNode;
	class	PixelTextureNode;
	class	PlaneSensorNode;
	class	PointLightNode;
	class	PointSetNode;
	class	PositionInterpolatorNode;
	class	ProximitySensorNode;
	class	ScalarInterpolatorNode;
	class	ScriptNode;
	class	ShapeNode;
	class	SoundNode;
	class	SphereNode;
	class	SphereSensorNode;
	class	SpotLightNode;
	class	SwitchNode;
	class	TextNode;
	class	TextureNode;
	class	TextureCoordinateNode;
	class	TextureTransformNode;
	class	TimeSensorNode;
	class	TouchSensorNode;
	class	TransformNode;
	class	ViewpointNode;
	class	VisibilitySensorNode;
	class	WorldInfoNode;
	
// 9. Networking component (X3D)
	class LoadSensorNode;
// 10. Grouping component (X3D)
	class StaticGroupNode;
// 11. Rendering component (X3D)
	class ColorRGBANode;
	class TriangleSetNode;
	class TriangleFanSetNode;
	class TriangleStripSetNode;
// 12. Shape component (X3D)
	class FillPropertiesNode;
	class LinePropertiesNode;
// 14. Geometry2D component (X3D)
	class Arc2DNode;
	class ArcClose2DNode;
	class Circle2DNode;
	class Disk2DNode;
	class Polyline2DNode;
	class Polypoint2DNode;
	class Rectangle2DNode;
	class TriangleSet2DNode;
// 18. Texturing component (x3D)
	class MultiTextureNode;
	class MultiTextureCoordinateNode;
	class MultiTextureTransformNode;
	class TextureCoordinateGeneratorNode;
// 19. Interpolation component (X3D)
	class CoordinateInterpolator2DNode;
	class PositionInterpolator2DNode;
// 21. Key device sensor component (X3D)
	class KeySensorNode;
	class StringSensorNode;
// 30. Event Utilities component (X3D)
	class BooleanFilterNode;
	class BooleanToggleNode;
	class BooleanTriggerNode;
	class BooleanSequencerNode;
	class IntegerTriggerNode;
	class IntegerSequencerNode;
	class TimeTriggerNode;
// Deprecated components (X3D)
	class NodeSequencerNode;
	class Shape2DNode;
	class BooleanTimeTriggerNode;
	class Transform2DNode;
	
	class	GroupingNode;
	class	Geometry3DNode;
	
	class	DEFNode;
	
	class Node : public LinkedListNode<Node>
	{
	
	public:
		String				*mName;
		int						mType;
		Vector<Field>		*mExposedField;
		Vector<Field>		*mEventInField;
		Vector<Field>		*mEventOutField;
		Vector<Field>		*mField;
		Vector<Field>		*mPrivateField;
		Vector<Node>		*mPrivateNodeVector;
		bool				*mInitialized;
		
		String				*mOrgName;
		int						mOrgType;
		Vector<Field>		*mOrgExposedField;
		Vector<Field>		*mOrgEventInField;
		Vector<Field>		*mOrgEventOutField;
		Vector<Field>		*mOrgField;
		Vector<Field>		*mOrgPrivateField;
		
	private:
		Node				*mParentNode;
		LinkedList<Node>	*mChildNodes;
		SceneGraph			*mSceneGraph;
		
#ifdef SUPPORT_JSAI
		JNode				*mJNode;
#endif
		
		void				*mValue;
		Node				*mReferenceNode;
		
	public:
	
		Node();
		
		Node(const int nodeType, const char * nodeName);
		
		virtual ~Node();
		
		void initializeMember();
		
		void remove();
		
		void setName(const char * name);
		char *getName();
		bool hasName();
		
		void setType(const int type);
		int getType();
		const char *getTypeString();
		
		////////////////////////////////////////////////
		//	Java
		////////////////////////////////////////////////
		
#ifdef SUPPORT_JSAI
		
		void createJavaNodeObject()
		{
			mJNode = new JNode(this);
		}
		
		void setJavaNodeObject(JNode *jnode)
		{
			mJNode = jnode;
		}
		
		JNode *getJavaNodeObject()
		{
			return mJNode;
		}
		
#endif
		
		////////////////////////////////////////////////
		//	Field
		////////////////////////////////////////////////
		
		Field *createField(int type);
		int getNAllFields();
		
		Field *findField(const char *name);
		bool hasMField();
		
		////////////////////////////////////////////////
		//	EventIn
		////////////////////////////////////////////////
		
		Field *getEventIn(const char * fieldString);
		int getNEventIn();
		void addEventIn(Field *field);
		void addEventIn(const char * name, Field *field);
		void addEventIn(const char * name, int fieldType);
		Field *getEventIn(int index);
		int getEventInNumber(Field *field);
		
		////////////////////////////////////////////////
		//	EventOut
		////////////////////////////////////////////////
		
		Field *getEventOut(const char *fieldString);
		int getNEventOut();
		void addEventOut(Field *field);
		void addEventOut(const char *name, Field *field);
		void addEventOut(const char * name, int fieldType);
		Field *getEventOut(int index);
		int getEventOutNumber(Field *field);
		
		////////////////////////////////////////////////
		//	ExposedField
		////////////////////////////////////////////////
		
		Field *getExposedField(const char * fieldString);
		int getNExposedFields();
		void addExposedField(Field *field);
		void addExposedField(const char * name, Field *field);
		void addExposedField(const char * name, int fieldType);
		Field *getExposedField(int index);
		int getExposedFieldNumber(Field *field);
		
		////////////////////////////////////////////////
		//	Field
		////////////////////////////////////////////////
		
		Field *getField(const char *fieldString);
		int getNFields();
		void addField(Field *field);
		void addField(const char * name, Field *field);
		void addField(const char * name, int fieldType);
		Field *getField(int index);
		int getFieldNumber(Field *field);
		
		////////////////////////////////////////////////
		//	PrivateField
		////////////////////////////////////////////////
		
		Field *getPrivateField(const char *fieldString);
		int getNPrivateFields();
		void addPrivateField(Field *field);
		void addPrivateField(const char * name, Field *field);
		Field *getPrivateField(int index);
		int getPrivateFieldNumber(Field *field);
		
		////////////////////////////////////////////////
		//	PrivateField
		////////////////////////////////////////////////
		
		int getNPrivateNodeElements();
		void addPrivateNodeElement(Node *node);
		Node *getPrivateNodeElementAt(int n);
		void removeAllNodeElement();
		
		////////////////////////////////////////////////
		//	Parent node
		////////////////////////////////////////////////
		
		void setParentNode(Node *parentNode);
		Node *getParentNode();
		bool isParentNode(Node *node);
		bool isAncestorNode(Node *node);
		
		////////////////////////////////////////////////
		//	Traversal node list
		////////////////////////////////////////////////
		
		Node *nextTraversal();
		Node *nextTraversalByType(const int type);
		Node *nextTraversalByName(const char *nameString);
		
		Node *nextTraversalSameType()
		{
			return nextTraversalByType(getType());
		}
		
		////////////////////////////////////////////////
		//	next node list
		////////////////////////////////////////////////
		
		Node *next();
		Node *next(const int type);
		
		////////////////////////////////////////////////
		//	child node list
		////////////////////////////////////////////////
		
		Node *getChildNodes();
		Node *getChildNodeByType(int type);
		Node *getChildNode(int n);
		
		int getNChildNodes();
		bool hasChildNodes();
		
		virtual bool isChildNodeType(Node *node) = 0;
		
		void addChildNode(Node *node, bool initialize = true);
		void addChildNodeAtFirst(Node *node, bool initialize = true);
		
		void moveChildNode(Node *node);
		void moveChildNodeAtFirst(Node *node);
		
		void deleteChildNodes(void);
		
		void removeRoutes();
		void removeSFNodes();
		void removeInstanceNodes();
		
		////////////////////////////////////////////////
		//	Add / Remove children (for Groupingnode)
		////////////////////////////////////////////////
		
		bool isChildNode(Node *parentNode, Node *node);
		bool isChildNode(Node *node);
		
		////////////////////////////////////////////////
		//	get child node list
		////////////////////////////////////////////////
		
		GroupingNode *getGroupingNodes();
		Geometry3DNode *getGeometry3DNode();
		TextureNode *getTextureNode();
		
		AnchorNode *getAnchorNodes()
		{
			return (AnchorNode *)getChildNodeByType(ANCHOR_NODE);
		}
		
		AppearanceNode *getAppearanceNodes()
		{
			return (AppearanceNode *)getChildNodeByType(APPEARANCE_NODE);
		}
		
		AudioClipNode *getAudioClipNodes()
		{
			return (AudioClipNode *)getChildNodeByType(AUDIOCLIP_NODE);
		}
		
		BackgroundNode *getBackgroundNodes()
		{
			return (BackgroundNode *)getChildNodeByType(BACKGROUND_NODE);
		}
		
		BillboardNode *getBillboardNodes()
		{
			return (BillboardNode *)getChildNodeByType(BILLBOARD_NODE);
		}
		
		BoxNode *getBoxeNodes()
		{
			return (BoxNode *)getChildNodeByType(BOX_NODE);
		}
		
		CollisionNode *getCollisionNodes()
		{
			return (CollisionNode *)getChildNodeByType(COLLISION_NODE);
		}
		
		ColorNode *getColorNodes()
		{
			return (ColorNode *)getChildNodeByType(COLOR_NODE);
		}
		
		ColorInterpolatorNode *getColorInterpolatorNodes()
		{
			return (ColorInterpolatorNode *)getChildNodeByType(COLORINTERPOLATOR_NODE);
		}
		
		ConeNode *getConeNodes()
		{
			return (ConeNode *)getChildNodeByType(CONE_NODE);
		}
		
		CoordinateNode *getCoordinateNodes()
		{
			return (CoordinateNode *)getChildNodeByType(COORDINATE_NODE);
		}
		
		CoordinateInterpolatorNode *getCoordinateInterpolatorNodes()
		{
			return (CoordinateInterpolatorNode *)getChildNodeByType(COORDINATEINTERPOLATOR_NODE);
		}
		
		CylinderNode *getCylinderNodes()
		{
			return (CylinderNode *)getChildNodeByType(CYLINDER_NODE);
		}
		
		CylinderSensorNode *getCylinderSensorNodes()
		{
			return (CylinderSensorNode *)getChildNodeByType(CYLINDERSENSOR_NODE);
		}
		
		DirectionalLightNode *getDirectionalLightNodes()
		{
			return (DirectionalLightNode *)getChildNodeByType(DIRECTIONALLIGHT_NODE);
		}
		
		ElevationGridNode *getElevationGridNodes()
		{
			return (ElevationGridNode *)getChildNodeByType(ELEVATIONGRID_NODE);
		}
		
		ExtrusionNode *getExtrusionNodes()
		{
			return (ExtrusionNode *)getChildNodeByType(EXTRUSION_NODE);
		}
		
		FogNode *getFogNodes()
		{
			return (FogNode *)getChildNodeByType(FOG_NODE);
		}
		
		FontStyleNode *getFontStyleNodes()
		{
			return (FontStyleNode *)getChildNodeByType(FONTSTYLE_NODE);
		}
		
		GroupNode *getGroupNodes()
		{
			return (GroupNode *)getChildNodeByType(GROUP_NODE);
		}
		
		ImageTextureNode *getImageTextureNodes()
		{
			return (ImageTextureNode *)getChildNodeByType(IMAGETEXTURE_NODE);
		}
		
		IndexedFaceSetNode *getIndexedFaceSetNodes()
		{
			return (IndexedFaceSetNode *)getChildNodeByType(INDEXEDFACESET_NODE);
		}
		
		IndexedLineSetNode *getIndexedLineSetNodes()
		{
			return (IndexedLineSetNode *)getChildNodeByType(INDEXEDLINESET_NODE);
		}
		
		InlineNode *getInlineNodes()
		{
			return (InlineNode *)getChildNodeByType(INLINE_NODE);
		}
		
		LODNode *getLODNodes()
		{
			return (LODNode *)getChildNodeByType(LOD_NODE);
		}
		
		MaterialNode *getMaterialNodes()
		{
			return (MaterialNode *)getChildNodeByType(MATERIAL_NODE);
		}
		
		MovieTextureNode *getMovieTextureNodes()
		{
			return (MovieTextureNode *)getChildNodeByType(MOVIETEXTURE_NODE);
		}
		
		NavigationInfoNode *getNavigationInfoNodes()
		{
			return (NavigationInfoNode *)getChildNodeByType(NAVIGATIONINFO_NODE);
		}
		
		NormalNode *getNormalNodes()
		{
			return (NormalNode *)getChildNodeByType(NORMAL_NODE);
		}
		
		NormalInterpolatorNode *getNormalInterpolatorNodes()
		{
			return (NormalInterpolatorNode *)getChildNodeByType(NORMALINTERPOLATOR_NODE);
		}
		
		OrientationInterpolatorNode *getOrientationInterpolatorNodes()
		{
			return (OrientationInterpolatorNode *)getChildNodeByType(ORIENTATIONINTERPOLATOR_NODE);
		}
		
		PixelTextureNode *getPixelTextureNodes()
		{
			return (PixelTextureNode *)getChildNodeByType(PIXELTEXTURE_NODE);
		}
		
		PlaneSensorNode *getPlaneSensorNodes()
		{
			return (PlaneSensorNode *)getChildNodeByType(PLANESENSOR_NODE);
		}
		
		PointLightNode *getPointLightNodes()
		{
			return (PointLightNode *)getChildNodeByType(POINTLIGHT_NODE);
		}
		
		PointSetNode *getPointSetNodes()
		{
			return (PointSetNode *)getChildNodeByType(POINTSET_NODE);
		}
		
		PositionInterpolatorNode *getPositionInterpolatorNodes()
		{
			return (PositionInterpolatorNode *)getChildNodeByType(POSITIONINTERPOLATOR_NODE);
		}
		
		ProximitySensorNode *getProximitySensorNodes()
		{
			return (ProximitySensorNode *)getChildNodeByType(PROXIMITYSENSOR_NODE);
		}
		
		ScalarInterpolatorNode *getScalarInterpolatorNodes()
		{
			return (ScalarInterpolatorNode *)getChildNodeByType(SCALARINTERPOLATOR_NODE);
		}
		
		ScriptNode *getScriptNodes()
		{
			return (ScriptNode *)getChildNodeByType(SCRIPT_NODE);
		}
		
		ShapeNode *getShapeNodes()
		{
			return (ShapeNode *)getChildNodeByType(SHAPE_NODE);
		}
		
		SoundNode *getSoundNodes()
		{
			return (SoundNode *)getChildNodeByType(SOUND_NODE);
		}
		
		SphereNode *getSphereNodes()
		{
			return (SphereNode *)getChildNodeByType(SPHERE_NODE);
		}
		
		SphereSensorNode *getSphereSensorNodes()
		{
			return (SphereSensorNode *)getChildNodeByType(SPHERESENSOR_NODE);
		}
		
		SpotLightNode *getSpotLightNodes()
		{
			return (SpotLightNode *)getChildNodeByType(SPOTLIGHT_NODE);
		}
		
		SwitchNode *getSwitchNodes()
		{
			return (SwitchNode *)getChildNodeByType(SWITCH_NODE);
		}
		
		TextNode *getTextNodes()
		{
			return (TextNode *)getChildNodeByType(TEXT_NODE);
		}
		
		TextureCoordinateNode *getTextureCoordinateNodes()
		{
			return (TextureCoordinateNode *)getChildNodeByType(TEXTURECOORDINATE_NODE);
		}
		
		TextureTransformNode *getTextureTransformNodes()
		{
			return (TextureTransformNode *)getChildNodeByType(TEXTURETRANSFORM_NODE);
		}
		
		TimeSensorNode *getTimeSensorNodes()
		{
			return (TimeSensorNode *)getChildNodeByType(TIMESENSOR_NODE);
		}
		
		TouchSensorNode *getTouchSensorNodes()
		{
			return (TouchSensorNode *)getChildNodeByType(TOUCHSENSOR_NODE);
		}
		
		TransformNode *getTransformNodes()
		{
			return (TransformNode *)getChildNodeByType(TRANSFORM_NODE);
		}
		
		ViewpointNode *getViewpointNodes()
		{
			return (ViewpointNode *)getChildNodeByType(VIEWPOINT_NODE);
		}
		
		VisibilitySensorNode *getVisibilitySensorNodes()
		{
			return (VisibilitySensorNode *)getChildNodeByType(VISIBILITYSENSOR_NODE);
		}
		
		WorldInfoNode *getWorldInfoNodes()
		{
			return (WorldInfoNode *)getChildNodeByType(WORLDINFO_NODE);
		}
		
		// 9. Networking component (X3D)
		
		LoadSensorNode *getLoadSensorNodes()
		{
			return (LoadSensorNode *)getChildNodeByType(LOADSENSOR_NODE);
		}
		
		// 10. Grouping component (X3D)
		
		StaticGroupNode *getStaticGroupNodes()
		{
			return (StaticGroupNode *)getChildNodeByType(STATICGROUP_NODE);
		}
		
		// 11. Rendering component (X3D)
		
		ColorRGBANode *getColorRGBANodes()
		{
			return (ColorRGBANode *)getChildNodeByType(COLORRGBA_NODE);
		}
		
		TriangleSetNode *getTriangleSetNodes()
		{
			return (TriangleSetNode *)getChildNodeByType(TRIANGLESET_NODE);
		}
		
		TriangleFanSetNode *getTriangleFanSetNodes()
		{
			return (TriangleFanSetNode *)getChildNodeByType(TRIANGLEFANSET_NODE);
		}
		
		TriangleStripSetNode *getTriangleStripSetNodes()
		{
			return (TriangleStripSetNode *)getChildNodeByType(TRIANGLESTRIPSET_NODE);
		}
		
		// 12. Shape component (X3D)
		
		FillPropertiesNode *getFillPropertiesNodes()
		{
			return (FillPropertiesNode *)getChildNodeByType(FILLPROPERTIES_NODE);
		}
		
		LinePropertiesNode *getLinePropertiesNodes()
		{
			return (LinePropertiesNode *)getChildNodeByType(LINEPROPERTIES_NODE);
		}
		
		// 14. Geometry2D component (X3D)
		
		Arc2DNode *getArc2DNodes()
		{
			return (Arc2DNode *)getChildNodeByType(ARC2D_NODE);
		}
		
		ArcClose2DNode *getArcClose2DNodes()
		{
			return (ArcClose2DNode *)getChildNodeByType(ARCCLOSE2D_NODE);
		}
		
		Circle2DNode *getCircle2DNodes()
		{
			return (Circle2DNode *)getChildNodeByType(CIRCLE2D_NODE);
		}
		
		Disk2DNode *getDisk2DNodes()
		{
			return (Disk2DNode *)getChildNodeByType(DISK2D_NODE);
		}
		
		Polyline2DNode *getPolyline2DNodes()
		{
			return (Polyline2DNode *)getChildNodeByType(POLYLINE2D_NODE);
		}
		
		Polypoint2DNode *getPolypoint2DNodes()
		{
			return (Polypoint2DNode *)getChildNodeByType(POLYPOINT2D_NODE);
		}
		
		Rectangle2DNode *getRectangle2DNodes()
		{
			return (Rectangle2DNode *)getChildNodeByType(RECTANGLE2D_NODE);
		}
		
		TriangleSet2DNode *getTriangleSet2DNodes()
		{
			return (TriangleSet2DNode *)getChildNodeByType(TRIANGLESET2D_NODE);
		}
		
		// 18. Texturing component (x3D)
		
		MultiTextureNode *getMultiTextureNodes()
		{
			return (MultiTextureNode *)getChildNodeByType(MULTITEXTURE_NODE);
		}
		
		MultiTextureCoordinateNode *getMultiTextureCoordinateNodes()
		{
			return (MultiTextureCoordinateNode *)getChildNodeByType(MULTITEXTURECOORD_NODE);
		}
		
		MultiTextureTransformNode *getMultiTextureTransformNodes()
		{
			return (MultiTextureTransformNode *)getChildNodeByType(MULTITEXTURETRANSFORM_NODE);
		}
		
		TextureCoordinateGeneratorNode *getTextureCoordinateGeneratorNodes()
		{
			return (TextureCoordinateGeneratorNode *)getChildNodeByType(TEXCOORDGEN_NODE);
		}
		
		// 19. Interpolation component (X3D)
		
		CoordinateInterpolator2DNode *getCoordinateInterpolator2DNodes()
		{
			return (CoordinateInterpolator2DNode *)getChildNodeByType(COORDINATEINTERPOLATOR2D_NODE);
		}
		
		PositionInterpolator2DNode *getPositionInterpolator2DNodes()
		{
			return (PositionInterpolator2DNode *)getChildNodeByType(POSITIONINTERPOLATOR2D_NODE);
		}
		
		// 21. Key device sensor component (X3D)
		
		KeySensorNode *getKeySensorNodes()
		{
			return (KeySensorNode *)getChildNodeByType(KEYSENSOR_NODE);
		}
		
		StringSensorNode *getStringSensorNodes()
		{
			return (StringSensorNode *)getChildNodeByType(STRINGSENSOR_NODE);
		}
		
		// 30. Event Utilities component (X3D)
		
		BooleanFilterNode *getBooleanFilterNodes()
		{
			return (BooleanFilterNode *)getChildNodeByType(BOOLEANFILTER_NODE);
		}
		
		BooleanToggleNode *getBooleanToggleNodes()
		{
			return (BooleanToggleNode *)getChildNodeByType(BOOLEANTOGGLE_NODE);
		}
		
		BooleanTriggerNode *getBooleanTriggerNodes()
		{
			return (BooleanTriggerNode *)getChildNodeByType(BOOLEANTRIGGER_NODE);
		}
		
		BooleanSequencerNode *getBooleanSequencerNodes()
		{
			return (BooleanSequencerNode *)getChildNodeByType(BOOLEANSEQUENCER_NODE);
		}
		
		IntegerTriggerNode *getIntegerTriggerNodes()
		{
			return (IntegerTriggerNode *)getChildNodeByType(INTEGERTRIGGER_NODE);
		}
		
		IntegerSequencerNode *getIntegerSequencerNodes()
		{
			return (IntegerSequencerNode *)getChildNodeByType(INTEGERSEQUENCER_NODE);
		}
		
		TimeTriggerNode *getTimeTriggerNodes()
		{
			return (TimeTriggerNode *)getChildNodeByType(TIMETRIGGER_NODE);
		}
		
		// Deprecated components (X3D)
		
		NodeSequencerNode *getNodeSequencerNodes()
		{
			return (NodeSequencerNode *)getChildNodeByType(NODESEQUENCER_NODE);
		}
		
		Shape2DNode *getShape2DNodes()
		{
			return (Shape2DNode *)getChildNodeByType(SHAPE2D_NODE);
		}
		
		BooleanTimeTriggerNode *getBooleanTimeTriggerNodes()
		{
			return (BooleanTimeTriggerNode *)getChildNodeByType(BOOLEANTIMETRIGGER_NODE);
		}
		
		Transform2DNode *getTransform2DNodes()
		{
			return (Transform2DNode *)getChildNodeByType(TRANSFORM2D_NODE);
		}
		
		////////////////////////////////////////////////
		//	is*
		////////////////////////////////////////////////
		
		bool isNode(const int type);
		bool isRootNode();
		bool isDEFNode();
		bool isInlineChildNode();
		
		bool isGroupingNode()
		{
			if(isAnchorNode() || isBillboardNode() || isCollisionNode() || isGroupNode() || isLODNode() || isSwitchNode() || isTransformNode())
				return true;
			return false;
		}
		
		bool isBoundedGroupingNode()
		{
			return isGroupingNode();
		}
		
		bool isSpecialGroupNode()
		{
			if(isInlineNode() || isLODNode() || isSwitchNode())
				return true;
			return false;
		}
		
		bool isCommonNode()
		{
			if(isLightNode() || isAudioClipNode() || isScriptNode() || isShapeNode() || isSoundNode() || isWorldInfoNode())
				return true;
			return false;
		}
		
		bool isLightNode()
		{
			if(isDirectionalLightNode() || isSpotLightNode() || isPointLightNode())
				return true;
			return false;
		}
		
		bool isGeometry3DNode()
		{
			if(isBoxNode() || isConeNode() || isCylinderNode() || isElevationGridNode() || isExtrusionNode() || isIndexedFaceSetNode() || isIndexedLineSetNode() || isPointSetNode() || isSphereNode() || isTextNode())
				return true;
			return false;
		}
		
		bool isGeometry3DPropertyNode()
		{
			if(isColorNode() || isCoordinateNode() || isNormalNode() || isTextureCoordinateNode())
				return true;
			return false;
		}
		
		bool isTextureNode()
		{
			if(isMovieTextureNode() || isPixelTextureNode() || isImageTextureNode())
				return true;
			return false;
		}
		
		bool isSensorNode()
		{
			if(isCylinderSensorNode() || isPlaneSensorNode() || isSphereSensorNode() || isProximitySensorNode() || isTimeSensorNode() || isTouchSensorNode() || isVisibilitySensorNode())
				return true;
			return false;
		}
		
		bool isInterpolatorNode()
		{
			if(isColorInterpolatorNode() || isCoordinateInterpolatorNode() || isNormalInterpolatorNode() || isOrientationInterpolatorNode() || isPositionInterpolatorNode() || isScalarInterpolatorNode())
				return true;
			return false;
		}
		
		bool isBindableNode()
		{
			if(isBackgroundNode() || isFogNode() || isNavigationInfoNode() || isViewpointNode())
				return true;
			return false;
		}
		
		// VRML97 component
		
		bool isAnchorNode()
		{
			return isNode(ANCHOR_NODE);
		}
		
		bool isAppearanceNode()
		{
			return isNode(APPEARANCE_NODE);
		}
		
		bool isAudioClipNode()
		{
			return isNode(AUDIOCLIP_NODE);
		}
		
		bool isBackgroundNode()
		{
			return isNode(BACKGROUND_NODE);
		}
		
		bool isBillboardNode()
		{
			return isNode(BILLBOARD_NODE);
		}
		
		bool isBoxNode()
		{
			return isNode(BOX_NODE);
		}
		
		bool isCollisionNode()
		{
			return isNode(COLLISION_NODE);
		}
		
		bool isColorNode()
		{
			return isNode(COLOR_NODE);
		}
		
		bool isColorInterpolatorNode()
		{
			return isNode(COLORINTERPOLATOR_NODE);
		}
		
		bool isConeNode()
		{
			return isNode(CONE_NODE);
		}
		
		bool isCoordinateNode()
		{
			return isNode(COORDINATE_NODE);
		}
		
		bool isCoordinateInterpolatorNode()
		{
			return isNode(COORDINATEINTERPOLATOR_NODE);
		}
		
		bool isCylinderNode()
		{
			return isNode(CYLINDER_NODE);
		}
		
		bool isCylinderSensorNode()
		{
			return isNode(CYLINDERSENSOR_NODE);
		}
		
		bool isDirectionalLightNode()
		{
			return isNode(DIRECTIONALLIGHT_NODE);
		}
		
		bool isElevationGridNode()
		{
			return isNode(ELEVATIONGRID_NODE);
		}
		
		bool isExtrusionNode()
		{
			return isNode(EXTRUSION_NODE);
		}
		
		bool isFogNode()
		{
			return isNode(FOG_NODE);
		}
		
		bool isFontStyleNode()
		{
			return isNode(FONTSTYLE_NODE);
		}
		
		bool isGroupNode()
		{
			return isNode(GROUP_NODE);
		}
		
		bool isImageTextureNode()
		{
			return isNode(IMAGETEXTURE_NODE);
		}
		
		bool isIndexedFaceSetNode()
		{
			return isNode(INDEXEDFACESET_NODE);
		}
		
		bool isIndexedLineSetNode()
		{
			return isNode(INDEXEDLINESET_NODE);
		}
		
		bool isInlineNode()
		{
			return isNode(INLINE_NODE);
		}
		
		bool isLODNode()
		{
			return isNode(LOD_NODE);
		}
		
		bool isMaterialNode()
		{
			return isNode(MATERIAL_NODE);
		}
		
		bool isMovieTextureNode()
		{
			return isNode(MOVIETEXTURE_NODE);
		}
		
		bool isNavigationInfoNode()
		{
			return isNode(NAVIGATIONINFO_NODE);
		}
		
		bool isNormalNode()
		{
			return isNode(NORMAL_NODE);
		}
		
		bool isNormalInterpolatorNode()
		{
			return isNode(NORMALINTERPOLATOR_NODE);
		}
		
		bool isOrientationInterpolatorNode()
		{
			return isNode(ORIENTATIONINTERPOLATOR_NODE);
		}
		
		bool isPixelTextureNode()
		{
			return isNode(PIXELTEXTURE_NODE);
		}
		
		bool isPlaneSensorNode()
		{
			return isNode(PLANESENSOR_NODE);
		}
		
		bool isPointLightNode()
		{
			return isNode(POINTLIGHT_NODE);
		}
		
		bool isPointSetNode()
		{
			return isNode(POINTSET_NODE);
		}
		
		bool isPositionInterpolatorNode()
		{
			return isNode(POSITIONINTERPOLATOR_NODE);
		}
		
		bool isProximitySensorNode()
		{
			return isNode(PROXIMITYSENSOR_NODE);
		}
		
		bool isScalarInterpolatorNode()
		{
			return isNode(SCALARINTERPOLATOR_NODE);
		}
		
		bool isScriptNode()
		{
			return isNode(SCRIPT_NODE);
		}
		
		bool isShapeNode()
		{
			return isNode(SHAPE_NODE);
		}
		
		bool isSoundNode()
		{
			return isNode(SOUND_NODE);
		}
		
		bool isSphereNode()
		{
			return isNode(SPHERE_NODE);
		}
		
		bool isSphereSensorNode()
		{
			return isNode(SPHERESENSOR_NODE);
		}
		
		bool isSpotLightNode()
		{
			return isNode(SPOTLIGHT_NODE);
		}
		
		bool isSwitchNode()
		{
			return isNode(SWITCH_NODE);
		}
		
		bool isTextNode()
		{
			return isNode(TEXT_NODE);
		}
		
		bool isTextureCoordinateNode()
		{
			return isNode(TEXTURECOORDINATE_NODE);
		}
		
		bool isTextureTransformNode()
		{
			return isNode(TEXTURETRANSFORM_NODE);
		}
		
		bool isTimeSensorNode()
		{
			return isNode(TIMESENSOR_NODE);
		}
		
		bool isTouchSensorNode()
		{
			return isNode(TOUCHSENSOR_NODE);
		}
		
		bool isTransformNode()
		{
			return isNode(TRANSFORM_NODE);
		}
		
		bool isViewpointNode()
		{
			return isNode(VIEWPOINT_NODE);
		}
		
		bool isVisibilitySensorNode()
		{
			return isNode(VISIBILITYSENSOR_NODE);
		}
		
		bool isWorldInfoNode()
		{
			return isNode(WORLDINFO_NODE);
		}
		
		// 9. Networking component (X3D)
		
		bool isLoadSensorNode()
		{
			return isNode(LOADSENSOR_NODE);
		}
		
		// 10. Grouping component (X3D)
		
		bool isStaticGroupNode()
		{
			return isNode(STATICGROUP_NODE);
		}
		
		// 11. Rendering component (X3D)
		
		bool isColorRGBANode()
		{
			return isNode(COLORRGBA_NODE);
		}
		
		bool isTriangleSetNode()
		{
			return isNode(TRIANGLESET_NODE);
		}
		
		bool isTriangleFanSetNode()
		{
			return isNode(TRIANGLEFANSET_NODE);
		}
		
		bool isTriangleStripSetNode()
		{
			return isNode(TRIANGLESTRIPSET_NODE);
		}
		
		// 12. Shape component (X3D)
		
		bool isFillPropertiesNode()
		{
			return isNode(FILLPROPERTIES_NODE);
		}
		
		bool isLinePropertiesNode()
		{
			return isNode(LINEPROPERTIES_NODE);
		}
		
		// 14. Geometry2D component (X3D)
		
		bool isArc2DNode()
		{
			return isNode(ARC2D_NODE);
		}
		
		bool isArcClose2DNode()
		{
			return isNode(ARCCLOSE2D_NODE);
		}
		
		bool isCircle2DNode()
		{
			return isNode(CIRCLE2D_NODE);
		}
		
		bool isDisk2DNode()
		{
			return isNode(DISK2D_NODE);
		}
		
		bool isPolyline2DNode()
		{
			return isNode(POLYLINE2D_NODE);
		}
		
		bool isPolypoint2DNode()
		{
			return isNode(POLYPOINT2D_NODE);
		}
		
		bool isRectangle2DNode()
		{
			return isNode(RECTANGLE2D_NODE);
		}
		
		bool isTriangleSet2DNode()
		{
			return isNode(TRIANGLESET2D_NODE);
		}
		
		// 18. Texturing component (x3D)
		
		bool isMultiTextureNode()
		{
			return isNode(MULTITEXTURE_NODE);
		}
		
		bool isMultiTextureCoordinateNode()
		{
			return isNode(MULTITEXTURECOORD_NODE);
		}
		
		bool isMultiTextureTransformNode()
		{
			return isNode(MULTITEXTURETRANSFORM_NODE);
		}
		
		bool isTextureCoordinateGeneratorNode()
		{
			return isNode(TEXCOORDGEN_NODE);
		}
		
		// 19. Interpolation component (X3D)
		
		bool isCoordinateInterpolator2DNode()
		{
			return isNode(COORDINATEINTERPOLATOR2D_NODE);
		}
		
		bool isPositionInterpolator2DNode()
		{
			return isNode(POSITIONINTERPOLATOR2D_NODE);
		}
		
		// 21. Key device sensor component (X3D)
		
		bool isKeySensorNode()
		{
			return isNode(KEYSENSOR_NODE);
		}
		
		bool isStringSensorNode()
		{
			return isNode(STRINGSENSOR_NODE);
		}
		
		// 30. Event Utilities component (X3D)
		
		bool isBooleanFilterNode()
		{
			return isNode(BOOLEANFILTER_NODE);
		}
		
		bool isBooleanToggleNode()
		{
			return isNode(BOOLEANTOGGLE_NODE);
		}
		
		bool isBooleanTriggerNode()
		{
			return isNode(BOOLEANTRIGGER_NODE);
		}
		
		bool isBooleanSequencerNode()
		{
			return isNode(BOOLEANSEQUENCER_NODE);
		}
		
		bool isIntegerTriggerNode()
		{
			return isNode(INTEGERTRIGGER_NODE);
		}
		
		bool isIntegerSequencerNode()
		{
			return isNode(INTEGERSEQUENCER_NODE);
		}
		
		bool isTimeTriggerNode()
		{
			return isNode(TIMETRIGGER_NODE);
		}
		
		// Deprecated components (X3D)
		
		bool isNodeSequencerNode()
		{
			return isNode(NODESEQUENCER_NODE);
		}
		
		bool isShape2DNode()
		{
			return isNode(SHAPE2D_NODE);
		}
		
		bool isBooleanTimeTriggerNode()
		{
			return isNode(BOOLEANTIMETRIGGER_NODE);
		}
		
		bool isTransform2DNode()
		{
			return isNode(TRANSFORM2D_NODE);
		}
		
		////////////////////////////////////////////////
		//	is* (XML)
		////////////////////////////////////////////////
		
		bool isXMLNode()
		{
			return isNode(XML_NODE);
		}
		
		////////////////////////////////////////////////
		//	isRouteNode (X3D)
		////////////////////////////////////////////////
		
		bool isRouteNode()
		{
			return isNode(ROUTE_NODE);
		}
		
		////////////////////////////////////////////////
		//	is (VRML97|X3D)Node
		////////////////////////////////////////////////
		
		bool isX3DNode()
		{
			if(isXMLNode())
				return true;
			return false;
		}
		
		bool isVRML97Node()
		{
			return !isX3DNode();
		}
		
		////////////////////////////////////////////////
		//	output (VRML97)
		////////////////////////////////////////////////
		
		char *getIndentLevelString(int nIndentLevel);
		char *getSpaceString(int nSpaces);
		
		void outputHead(std::ostream& printStream, char *indentString);
		
		void outputTail(std::ostream& printStream, char * indentString);
		
		virtual void outputContext(std::ostream &printStream, char *indentString) = 0;
		
		void outputContext(std::ostream& printStream, char *indentString1, char *indentString2);
		
		void output(std::ostream& printStream, int indentLevet);
		
		void print(std::ostream& printStream, int indentLevel)
		{
			output(printStream, indentLevel);
		}
		
		void print()
		{
			output(std::cout, 0);
		}
		
		void save(std::ofstream outputStream)
		{
			output(outputStream, 0);
		}
		
		int save(const char * filename)
		{
			std::ofstream outputFile(filename, std::ios::out);
			if(outputFile)
			{
				output(outputFile, 0);
				return 1;
			}
			else
				return 0;
		}
		
		////////////////////////////////////////////////
		//	output (XML)
		////////////////////////////////////////////////
		
		void outputXML(std::ostream& printStream, int indentLevet);
		void outputXMLField(std::ostream& printStream, Field *field, int indentLevel);
		void outputXMLField(std::ostream& printStream, Field *field, int indentLevel, bool isSingleLine);
		
		void printXML(std::ostream& printStream, int indentLevel)
		{
			outputXML(printStream, indentLevel);
		}
		
		void printXML()
		{
			outputXML(std::cout, 0);
		}
		
		int saveXML(const char * filename)
		{
			std::ofstream outputFile(filename, std::ios::out);
			if(outputFile)
			{
				output(outputFile, 0);
				return 1;
			}
			else
				return 0;
		}
		
		
		////////////////////////////////////////////////
		//	Virtual functions
		////////////////////////////////////////////////
		
		virtual void update()		= 0;
		virtual void initialize()	= 0;
		virtual void uninitialize()	= 0;
		
		////////////////////////////////////////////////
		//	Transform matrix
		////////////////////////////////////////////////
		
		void	getTransformMatrix(SFMatrix *matrix);
		void	getTransformMatrix(float value[4][4]);
		
		////////////////////////////////////////////////
		//	Translation matrix
		////////////////////////////////////////////////
		
		void	getTranslationMatrix(SFMatrix *matrix);
		void	getTranslationMatrix(float value[4][4]);
		
		////////////////////////////////////////////////
		//	SceneGraph
		////////////////////////////////////////////////
		
		void setSceneGraph(SceneGraph *sceneGraph);
		SceneGraph	*getSceneGraph();
		
		////////////////////////////////////////////////
		//	Route
		////////////////////////////////////////////////
		
		void		sendEvent(Field *eventOutField);
		void		sendEvent(const char *eventOutFieldString);
		
		////////////////////////////////////////////////
		//	Value
		////////////////////////////////////////////////
		
		void		setValue(void *value)
		{
			mValue = value;
		}
		void		*getValue()
		{
			return mValue;
		}
		
		////////////////////////////////////////////////
		//	Initialized
		////////////////////////////////////////////////
		
		void		setInitialized(bool flag)
		{
			*mInitialized = flag;
		}
		bool		isInitialized()
		{
			return *mInitialized;
		}
		
		////////////////////////////////////////////////
		//	BoundingBox
		////////////////////////////////////////////////
		
		virtual void recomputeBoundingBox()
		{
		}
		
		////////////////////////////////////////////////
		//	DisplayList
		////////////////////////////////////////////////
		
#ifdef SUPPORT_OPENGL
		
		virtual void recomputeDisplayList()
		{
		}
		
#endif
		
		////////////////////////////////////////////////
		//	Instance node
		////////////////////////////////////////////////
		
		bool isInstanceNode()
		{
			return (getReferenceNode() != NULL ? true : false);
		}
		
		void setReferenceNodeMembers(Node *node);
		
		void setOriginalMembers();
		
		void setReferenceNode(Node *node)
		{
			mReferenceNode = node;
		}
		
		Node *getReferenceNode()
		{
			return mReferenceNode;
		}
		
		void setAsInstanceNode(Node *node)
		{
			setReferenceNode(node);
			setReferenceNodeMembers(node);
		}
		
		Node *createInstanceNode();
		
		////////////////////////////////////////////////
		//	DEF node
		////////////////////////////////////////////////
		
		DEFNode *createDEFNode();
	};
	
}

#endif
