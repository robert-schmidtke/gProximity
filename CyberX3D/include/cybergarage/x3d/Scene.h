/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	Scene.h
*
******************************************************************/

#ifndef _CX3D_SCENE_H_
#define _CX3D_SCENE_H_

#include <cybergarage/x3d/NodeList.h>
#include <cybergarage/x3d/Route.h>
#include <cybergarage/x3d/X3DNodes.h>

namespace CyberX3D
{

	class Scene
	{
	
		NodeList					mNodeList;
		LinkedList<Route>	mRouteList;
		
	public:
	
		Scene();
		~Scene();
		
		NodeList *getNodeList()
		{
			return &mNodeList;
		}
		
		Node *getRootNode()
		{
			return (Node *)mNodeList.getRootNode();
		}
		
		Node *getNodes()
		{
			return (Node *)mNodeList.getNodes();
		}
		
		///////////////////////////////////////////////
		//	Load
		///////////////////////////////////////////////
		
		void clearNodeList()
		{
			mNodeList.deleteNodes();
		}
		
		void clearRouteList()
		{
			mRouteList.deleteNodes();
		}
		
		///////////////////////////////////////////////
		//	Praser action
		///////////////////////////////////////////////
		
		void addNode(Node *node, bool initialize = true);
		void addNodeAtFirst(Node *node, bool initialize = true);
		
		void moveNode(Node *node);
		void moveNodeAtFirst(Node *node);
		
		////////////////////////////////////////////////
		//	find node
		////////////////////////////////////////////////
		
		Node *findNode(const char *name);
		Node *findNode(const int type);
		Node *findNode(const int type, const char *name);
		
		Node *findLastNode(const char *name);
		Node *findDEFNode(const char *name);
		
		bool hasNode(Node *targetNode);
		
		///////////////////////////////////////////////
		//	ROUTE
		///////////////////////////////////////////////
		
		Route *getRoutes();
		Route *getRoute(Node *eventOutNode, Field *eventOutField, Node *eventInNode, Field *eventInField);
		void addRoute(Route *route);
		Route *addRoute(const char *eventOutNodeName, const char *eventOutFieldName, const char *eventInNodeName, const char *eventInFieldName);
		Route *addRoute(Node *eventOutNode, Field *eventOutField, Node *eventInNode, Field *eventInField);
		void deleteRoute(Node *eventOutNode, Field *eventOutField, Node *eventInNode, Field *eventInField);
		void deleteRoutes(Node *node);
		void deleteEventInFieldRoutes(Node *node, Field *field);
		void deleteEventOutFieldRoutes(Node *node, Field *field);
		void deleteRoutes(Node *node, Field *field);
		void deleteRoute(Route *deleteRoute);
		void removeRoute(Node *eventOutNode, Field *eventOutField, Node *eventInNode, Field *eventInField);
		void removeRoutes(Node *node);
		void removeEventInFieldRoutes(Node *node, Field *field);
		void removeEventOutFieldRoutes(Node *node, Field *field);
		void removeRoutes(Node *node, Field *field);
		void removeRoute(Route *removeRoute);
		
		////////////////////////////////////////////////
		//	find*Node
		////////////////////////////////////////////////
		
		GroupingNode *findGroupingNode()
		{
			for(Node *node = (getRootNode())->nextTraversal() ; node; node = node->nextTraversal())
			{
				if(node->isGroupingNode())
					return (GroupingNode *)node;
			}
			return NULL;
		}
		
		AnchorNode *findAnchorNode()
		{
			return (AnchorNode *)findNode(ANCHOR_NODE);
		}
		
		AppearanceNode *findAppearanceNode()
		{
			return (AppearanceNode *)findNode(APPEARANCE_NODE);
		}
		
		AudioClipNode *findAudioClipNode()
		{
			return (AudioClipNode *)findNode(AUDIOCLIP_NODE);
		}
		
		BackgroundNode *findBackgroundNode()
		{
			return (BackgroundNode *)findNode(BACKGROUND_NODE);
		}
		
		BillboardNode *findBillboardNode()
		{
			return (BillboardNode *)findNode(BILLBOARD_NODE);
		}
		
		BoxNode *findBoxNode()
		{
			return (BoxNode *)findNode(BOX_NODE);
		}
		
		CollisionNode *findCollisionNode()
		{
			return (CollisionNode *)findNode(COLLISION_NODE);
		}
		
		ColorNode *findColorNode()
		{
			return (ColorNode *)findNode(COLOR_NODE);
		}
		
		ColorInterpolatorNode *findColorInterpolatorNode()
		{
			return (ColorInterpolatorNode *)findNode(COLORINTERPOLATOR_NODE);
		}
		
		ConeNode *findConeNode()
		{
			return (ConeNode *)findNode(CONE_NODE);
		}
		
		CoordinateNode *findCoordinateNode()
		{
			return (CoordinateNode *)findNode(COORDINATE_NODE);
		}
		
		CoordinateInterpolatorNode *findCoordinateInterpolatorNode()
		{
			return (CoordinateInterpolatorNode *)findNode(COORDINATEINTERPOLATOR_NODE);
		}
		
		CylinderNode *findCylinderNode()
		{
			return (CylinderNode *)findNode(CYLINDER_NODE);
		}
		
		CylinderSensorNode *findCylinderSensorNode()
		{
			return (CylinderSensorNode *)findNode(CYLINDERSENSOR_NODE);
		}
		
		DirectionalLightNode *findDirectionalLightNode()
		{
			return (DirectionalLightNode *)findNode(DIRECTIONALLIGHT_NODE);
		}
		
		ElevationGridNode *findElevationGridNode()
		{
			return (ElevationGridNode *)findNode(ELEVATIONGRID_NODE);
		}
		
		ExtrusionNode *findExtrusionNode()
		{
			return (ExtrusionNode *)findNode(EXTRUSION_NODE);
		}
		
		FogNode *findFogNode()
		{
			return (FogNode *)findNode(FOG_NODE);
		}
		
		FontStyleNode *findFontStyleNode()
		{
			return (FontStyleNode *)findNode(FONTSTYLE_NODE);
		}
		
		GroupNode *findGroupNode()
		{
			return (GroupNode *)findNode(GROUP_NODE);
		}
		
		ImageTextureNode *findImageTextureNode()
		{
			return (ImageTextureNode *)findNode(IMAGETEXTURE_NODE);
		}
		
		IndexedFaceSetNode *findIndexedFaceSetNode()
		{
			return (IndexedFaceSetNode *)findNode(INDEXEDFACESET_NODE);
		}
		
		IndexedLineSetNode *findIndexedLineSetNode()
		{
			return (IndexedLineSetNode *)findNode(INDEXEDLINESET_NODE);
		}
		
		InlineNode *findInlineNode()
		{
			return (InlineNode *)findNode(INLINE_NODE);
		}
		
		LODNode *findLODNode()
		{
			return (LODNode *)findNode(LOD_NODE);
		}
		
		MaterialNode *findMaterialNode()
		{
			return (MaterialNode *)findNode(MATERIAL_NODE);
		}
		
		MovieTextureNode *findMovieTextureNode()
		{
			return (MovieTextureNode *)findNode(MOVIETEXTURE_NODE);
		}
		
		NavigationInfoNode *findNavigationInfoNode()
		{
			return (NavigationInfoNode *)findNode(NAVIGATIONINFO_NODE);
		}
		
		NormalNode *findNormalNode()
		{
			return (NormalNode *)findNode(NORMAL_NODE);
		}
		
		NormalInterpolatorNode *findNormalInterpolatorNode()
		{
			return (NormalInterpolatorNode *)findNode(NORMALINTERPOLATOR_NODE);
		}
		
		OrientationInterpolatorNode *findOrientationInterpolatorNode()
		{
			return (OrientationInterpolatorNode *)findNode(ORIENTATIONINTERPOLATOR_NODE);
		}
		
		PixelTextureNode *findPixelTextureNode()
		{
			return (PixelTextureNode *)findNode(PIXELTEXTURE_NODE);
		}
		
		PlaneSensorNode *findPlaneSensorNode()
		{
			return (PlaneSensorNode *)findNode(PLANESENSOR_NODE);
		}
		
		PointLightNode *findPointLightNode()
		{
			return (PointLightNode *)findNode(POINTLIGHT_NODE);
		}
		
		PointSetNode *findPointSetNode()
		{
			return (PointSetNode *)findNode(POINTSET_NODE);
		}
		
		PositionInterpolatorNode *findPositionInterpolatorNode()
		{
			return (PositionInterpolatorNode *)findNode(POSITIONINTERPOLATOR_NODE);
		}
		
		ProximitySensorNode *findProximitySensorNode()
		{
			return (ProximitySensorNode *)findNode(PROXIMITYSENSOR_NODE);
		}
		
		ScalarInterpolatorNode *findScalarInterpolatorNode()
		{
			return (ScalarInterpolatorNode *)findNode(SCALARINTERPOLATOR_NODE);
		}
		
		ScriptNode *findScriptNode()
		{
			return (ScriptNode *)findNode(SCRIPT_NODE);
		}
		
		ShapeNode *findShapeNode()
		{
			return (ShapeNode *)findNode(SHAPE_NODE);
		}
		
		SoundNode *findSoundNode()
		{
			return (SoundNode *)findNode(SOUND_NODE);
		}
		
		SphereNode *findSphereNode()
		{
			return (SphereNode *)findNode(SPHERE_NODE);
		}
		
		SphereSensorNode *findSphereSensorNode()
		{
			return (SphereSensorNode *)findNode(SPHERESENSOR_NODE);
		}
		
		SpotLightNode *findSpotLightNode()
		{
			return (SpotLightNode *)findNode(SPOTLIGHT_NODE);
		}
		
		SwitchNode *findSwitchNode()
		{
			return (SwitchNode *)findNode(SWITCH_NODE);
		}
		
		TextNode *findTextNode()
		{
			return (TextNode *)findNode(TEXT_NODE);
		}
		
		TextureCoordinateNode *findTextureCoordinateNode()
		{
			return (TextureCoordinateNode *)findNode(TEXTURECOORDINATE_NODE);
		}
		
		TextureTransformNode *findTextureTransformNode()
		{
			return (TextureTransformNode *)findNode(TEXTURETRANSFORM_NODE);
		}
		
		TimeSensorNode *findTimeSensorNode()
		{
			return (TimeSensorNode *)findNode(TIMESENSOR_NODE);
		}
		
		TouchSensorNode *findTouchSensorNode()
		{
			return (TouchSensorNode *)findNode(TOUCHSENSOR_NODE);
		}
		
		TransformNode *findTransformNode()
		{
			return (TransformNode *)findNode(TRANSFORM_NODE);
		}
		
		ViewpointNode *findViewpointNode()
		{
			return (ViewpointNode *)findNode(VIEWPOINT_NODE);
		}
		
		VisibilitySensorNode *findVisibilitySensorNode()
		{
			return (VisibilitySensorNode *)findNode(VISIBILITYSENSOR_NODE);
		}
		
		WorldInfoNode *findWorldInfoNode()
		{
			return (WorldInfoNode *)findNode(WORLDINFO_NODE);
		}
		
		// Scene (X3D)
		
		SceneNode *findSceneNode()
		{
			return (SceneNode *)findNode(SCENE_NODE);
		}
		
		// 9. Networking component (X3D)
		
		LoadSensorNode *findLoadSensorNode()
		{
			return (LoadSensorNode *)findNode(LOADSENSOR_NODE);
		}
		
		// 10. Grouping component (X3D)
		
		StaticGroupNode *findStaticGroupNode()
		{
			return (StaticGroupNode *)findNode(STATICGROUP_NODE);
		}
		
		// 11. Rendering component (X3D)
		
		ColorRGBANode *findColorRGBANode()
		{
			return (ColorRGBANode *)findNode(COLORRGBA_NODE);
		}
		
		TriangleSetNode *findTriangleSetNode()
		{
			return (TriangleSetNode *)findNode(TRIANGLESET_NODE);
		}
		
		TriangleFanSetNode *findTriangleFanSetNode()
		{
			return (TriangleFanSetNode *)findNode(TRIANGLEFANSET_NODE);
		}
		
		TriangleStripSetNode *findTriangleStripSetNode()
		{
			return (TriangleStripSetNode *)findNode(TRIANGLESTRIPSET_NODE);
		}
		
		// 12. Shape component (X3D)
		
		FillPropertiesNode *findFillPropertiesNode()
		{
			return (FillPropertiesNode *)findNode(FILLPROPERTIES_NODE);
		}
		
		LinePropertiesNode *findLinePropertiesNode()
		{
			return (LinePropertiesNode *)findNode(LINEPROPERTIES_NODE);
		}
		
		// 14. Geometry2D component (X3D)
		
		Arc2DNode *findArc2DNode()
		{
			return (Arc2DNode *)findNode(ARC2D_NODE);
		}
		
		ArcClose2DNode *findArcClose2DNode()
		{
			return (ArcClose2DNode *)findNode(ARCCLOSE2D_NODE);
		}
		
		Circle2DNode *findCircle2DNode()
		{
			return (Circle2DNode *)findNode(CIRCLE2D_NODE);
		}
		
		Disk2DNode *findDisk2DNode()
		{
			return (Disk2DNode *)findNode(DISK2D_NODE);
		}
		
		Polyline2DNode *findPolyline2DNode()
		{
			return (Polyline2DNode *)findNode(POLYLINE2D_NODE);
		}
		
		Polypoint2DNode *findPolypoint2DNode()
		{
			return (Polypoint2DNode *)findNode(POLYPOINT2D_NODE);
		}
		
		Rectangle2DNode *findRectangle2DNode()
		{
			return (Rectangle2DNode *)findNode(RECTANGLE2D_NODE);
		}
		
		TriangleSet2DNode *findTriangleSet2DNode()
		{
			return (TriangleSet2DNode *)findNode(TRIANGLESET2D_NODE);
		}
		
		// 18. Texturing component (x3D)
		
		MultiTextureNode *findMultiTextureNode()
		{
			return (MultiTextureNode *)findNode(MULTITEXTURE_NODE);
		}
		
		MultiTextureCoordinateNode *findMultiTextureCoordinateNode()
		{
			return (MultiTextureCoordinateNode *)findNode(MULTITEXTURECOORD_NODE);
		}
		
		MultiTextureTransformNode *findMultiTextureTransformNode()
		{
			return (MultiTextureTransformNode *)findNode(MULTITEXTURETRANSFORM_NODE);
		}
		
		TextureCoordinateGeneratorNode *findTextureCoordinateGeneratorNode()
		{
			return (TextureCoordinateGeneratorNode *)findNode(TEXCOORDGEN_NODE);
		}
		
		// 19. Interpolation component (X3D)
		
		CoordinateInterpolator2DNode *findCoordinateInterpolator2DNode()
		{
			return (CoordinateInterpolator2DNode *)findNode(COORDINATEINTERPOLATOR2D_NODE);
		}
		
		PositionInterpolator2DNode *findPositionInterpolator2DNode()
		{
			return (PositionInterpolator2DNode *)findNode(POSITIONINTERPOLATOR2D_NODE);
		}
		
		// 21. Key device sensor component (X3D)
		
		KeySensorNode *findKeySensorNode()
		{
			return (KeySensorNode *)findNode(KEYSENSOR_NODE);
		}
		
		StringSensorNode *findStringSensorNode()
		{
			return (StringSensorNode *)findNode(STRINGSENSOR_NODE);
		}
		
		// 30. Event Utilities component (X3D)
		
		BooleanFilterNode *findBooleanFilterNode()
		{
			return (BooleanFilterNode *)findNode(BOOLEANFILTER_NODE);
		}
		
		BooleanToggleNode *findBooleanToggleNode()
		{
			return (BooleanToggleNode *)findNode(BOOLEANTOGGLE_NODE);
		}
		
		BooleanTriggerNode *findBooleanTriggerNode()
		{
			return (BooleanTriggerNode *)findNode(BOOLEANTRIGGER_NODE);
		}
		
		BooleanSequencerNode *findBooleanSequencerNode()
		{
			return (BooleanSequencerNode *)findNode(BOOLEANSEQUENCER_NODE);
		}
		
		IntegerTriggerNode *findIntegerTriggerNode()
		{
			return (IntegerTriggerNode *)findNode(INTEGERTRIGGER_NODE);
		}
		
		IntegerSequencerNode *findIntegerSequencerNode()
		{
			return (IntegerSequencerNode *)findNode(INTEGERSEQUENCER_NODE);
		}
		
		TimeTriggerNode *findTimeTriggerNode()
		{
			return (TimeTriggerNode *)findNode(TIMETRIGGER_NODE);
		}
		
		// Deprecated components (X3D)
		
		NodeSequencerNode *findNodeSequencerNode()
		{
			return (NodeSequencerNode *)findNode(NODESEQUENCER_NODE);
		}
		
		Shape2DNode *findShape2DNode()
		{
			return (Shape2DNode *)findNode(SHAPE2D_NODE);
		}
		
		BooleanTimeTriggerNode *findBooleanTimeTriggerNode()
		{
			return (BooleanTimeTriggerNode *)findNode(BOOLEANTIMETRIGGER_NODE);
		}
		
		Transform2DNode *findTransform2DNode()
		{
			return (Transform2DNode *)findNode(TRANSFORM2D_NODE);
		}
		
		////////////////////////////////////////////////
		//	find*(const char *name)
		////////////////////////////////////////////////
		
		
		AnchorNode *findAnchorNode(const char *name)
		{
			return (AnchorNode *)findNode(ANCHOR_NODE, name);
		}
		
		AppearanceNode *findAppearanceNode(const char *name)
		{
			return (AppearanceNode *)findNode(APPEARANCE_NODE, name);
		}
		
		AudioClipNode *findAudioClipNode(const char *name)
		{
			return (AudioClipNode *)findNode(AUDIOCLIP_NODE, name);
		}
		
		BackgroundNode *findBackgroundNode(const char *name)
		{
			return (BackgroundNode *)findNode(BACKGROUND_NODE, name);
		}
		
		BillboardNode *findBillboardNode(const char *name)
		{
			return (BillboardNode *)findNode(BILLBOARD_NODE, name);
		}
		
		BoxNode *findBoxNode(const char *name)
		{
			return (BoxNode *)findNode(BOX_NODE, name);
		}
		
		CollisionNode *findCollisionNode(const char *name)
		{
			return (CollisionNode *)findNode(COLLISION_NODE, name);
		}
		
		ColorNode *findColorNode(const char *name)
		{
			return (ColorNode *)findNode(COLOR_NODE, name);
		}
		
		ColorInterpolatorNode *findColorInterpolatorNode(const char *name)
		{
			return (ColorInterpolatorNode *)findNode(COLORINTERPOLATOR_NODE, name);
		}
		
		ConeNode *findConeNode(const char *name)
		{
			return (ConeNode *)findNode(CONE_NODE, name);
		}
		
		CoordinateNode *findCoordinateNode(const char *name)
		{
			return (CoordinateNode *)findNode(COORDINATE_NODE, name);
		}
		
		CoordinateInterpolatorNode *findCoordinateInterpolatorNode(const char *name)
		{
			return (CoordinateInterpolatorNode *)findNode(COORDINATEINTERPOLATOR_NODE, name);
		}
		
		CylinderNode *findCylinderNode(const char *name)
		{
			return (CylinderNode *)findNode(CYLINDER_NODE, name);
		}
		
		CylinderSensorNode *findCylinderSensorNode(const char *name)
		{
			return (CylinderSensorNode *)findNode(CYLINDERSENSOR_NODE, name);
		}
		
		DirectionalLightNode *findDirectionalLightNode(const char *name)
		{
			return (DirectionalLightNode *)findNode(DIRECTIONALLIGHT_NODE, name);
		}
		
		ElevationGridNode *findElevationGridNode(const char *name)
		{
			return (ElevationGridNode *)findNode(ELEVATIONGRID_NODE, name);
		}
		
		ExtrusionNode *findExtrusionNode(const char *name)
		{
			return (ExtrusionNode *)findNode(EXTRUSION_NODE, name);
		}
		
		FogNode *findFogNode(const char *name)
		{
			return (FogNode *)findNode(FOG_NODE, name);
		}
		
		FontStyleNode *findFontStyleNode(const char *name)
		{
			return (FontStyleNode *)findNode(FONTSTYLE_NODE, name);
		}
		
		GroupNode *findGroupNode(const char *name)
		{
			return (GroupNode *)findNode(GROUP_NODE, name);
		}
		
		ImageTextureNode *findImageTextureNode(const char *name)
		{
			return (ImageTextureNode *)findNode(IMAGETEXTURE_NODE, name);
		}
		
		IndexedFaceSetNode *findIndexedFaceSetNode(const char *name)
		{
			return (IndexedFaceSetNode *)findNode(INDEXEDFACESET_NODE, name);
		}
		
		IndexedLineSetNode *findIndexedLineSetNode(const char *name)
		{
			return (IndexedLineSetNode *)findNode(INDEXEDLINESET_NODE, name);
		}
		
		InlineNode *findInlineNode(const char *name)
		{
			return (InlineNode *)findNode(INLINE_NODE, name);
		}
		
		LODNode *findLODNode(const char *name)
		{
			return (LODNode *)findNode(LOD_NODE, name);
		}
		
		MaterialNode *findMaterialNode(const char *name)
		{
			return (MaterialNode *)findNode(MATERIAL_NODE, name);
		}
		
		MovieTextureNode *findMovieTextureNode(const char *name)
		{
			return (MovieTextureNode *)findNode(MOVIETEXTURE_NODE, name);
		}
		
		NavigationInfoNode *findNavigationInfoNode(const char *name)
		{
			return (NavigationInfoNode *)findNode(NAVIGATIONINFO_NODE, name);
		}
		
		NormalNode *findNormalNode(const char *name)
		{
			return (NormalNode *)findNode(NORMAL_NODE, name);
		}
		
		NormalInterpolatorNode *findNormalInterpolatorNode(const char *name)
		{
			return (NormalInterpolatorNode *)findNode(NORMALINTERPOLATOR_NODE, name);
		}
		
		OrientationInterpolatorNode *findOrientationInterpolatorNode(const char *name)
		{
			return (OrientationInterpolatorNode *)findNode(ORIENTATIONINTERPOLATOR_NODE, name);
		}
		
		PixelTextureNode *findPixelTextureNode(const char *name)
		{
			return (PixelTextureNode *)findNode(PIXELTEXTURE_NODE, name);
		}
		
		PlaneSensorNode *findPlaneSensorNode(const char *name)
		{
			return (PlaneSensorNode *)findNode(PLANESENSOR_NODE, name);
		}
		
		PointLightNode *findPointLightNode(const char *name)
		{
			return (PointLightNode *)findNode(POINTLIGHT_NODE, name);
		}
		
		PointSetNode *findPointSetNode(const char *name)
		{
			return (PointSetNode *)findNode(POINTSET_NODE, name);
		}
		
		PositionInterpolatorNode *findPositionInterpolatorNode(const char *name)
		{
			return (PositionInterpolatorNode *)findNode(POSITIONINTERPOLATOR_NODE, name);
		}
		
		ProximitySensorNode *findProximitySensorNode(const char *name)
		{
			return (ProximitySensorNode *)findNode(PROXIMITYSENSOR_NODE, name);
		}
		
		ScalarInterpolatorNode *findScalarInterpolatorNode(const char *name)
		{
			return (ScalarInterpolatorNode *)findNode(SCALARINTERPOLATOR_NODE, name);
		}
		
		ScriptNode *findScriptNode(const char *name)
		{
			return (ScriptNode *)findNode(SCRIPT_NODE, name);
		}
		
		ShapeNode *findShapeNode(const char *name)
		{
			return (ShapeNode *)findNode(SHAPE_NODE, name);
		}
		
		SoundNode *findSoundNode(const char *name)
		{
			return (SoundNode *)findNode(SOUND_NODE, name);
		}
		
		SphereNode *findSphereNode(const char *name)
		{
			return (SphereNode *)findNode(SPHERE_NODE, name);
		}
		
		SphereSensorNode *findSphereSensorNode(const char *name)
		{
			return (SphereSensorNode *)findNode(SPHERESENSOR_NODE, name);
		}
		
		SpotLightNode *findSpotLightNode(const char *name)
		{
			return (SpotLightNode *)findNode(SPOTLIGHT_NODE, name);
		}
		
		SwitchNode *findSwitchNode(const char *name)
		{
			return (SwitchNode *)findNode(SWITCH_NODE, name);
		}
		
		TextNode *findTextNode(const char *name)
		{
			return (TextNode *)findNode(TEXT_NODE, name);
		}
		
		TextureCoordinateNode *findTextureCoordinateNode(const char *name)
		{
			return (TextureCoordinateNode *)findNode(TEXTURECOORDINATE_NODE, name);
		}
		
		TextureTransformNode *findTextureTransformNode(const char *name)
		{
			return (TextureTransformNode *)findNode(TEXTURETRANSFORM_NODE, name);
		}
		
		TimeSensorNode *findTimeSensorNode(const char *name)
		{
			return (TimeSensorNode *)findNode(TIMESENSOR_NODE, name);
		}
		
		TouchSensorNode *findTouchSensorNode(const char *name)
		{
			return (TouchSensorNode *)findNode(TOUCHSENSOR_NODE, name);
		}
		
		TransformNode *findTransformNode(const char *name)
		{
			return (TransformNode *)findNode(TRANSFORM_NODE, name);
		}
		
		ViewpointNode *findViewpointNode(const char *name)
		{
			return (ViewpointNode *)findNode(VIEWPOINT_NODE, name);
		}
		
		VisibilitySensorNode *findVisibilitySensorNode(const char *name)
		{
			return (VisibilitySensorNode *)findNode(VISIBILITYSENSOR_NODE, name);
		}
		
		WorldInfoNode *findWorldInfoNode(const char *name)
		{
			return (WorldInfoNode *)findNode(WORLDINFO_NODE, name);
		}
		
		// 9. Networking component (X3D)
		
		LoadSensorNode *findLoadSensorNode(const char *name)
		{
			return (LoadSensorNode *)findNode(LOADSENSOR_NODE, name);
		}
		
		// 10. Grouping component (X3D)
		
		StaticGroupNode *findStaticGroupNode(const char *name)
		{
			return (StaticGroupNode *)findNode(STATICGROUP_NODE, name);
		}
		
		// 11. Rendering component (X3D)
		
		ColorRGBANode *findColorRGBANode(const char *name)
		{
			return (ColorRGBANode *)findNode(COLORRGBA_NODE, name);
		}
		
		TriangleSetNode *findTriangleSetNode(const char *name)
		{
			return (TriangleSetNode *)findNode(TRIANGLESET_NODE, name);
		}
		
		TriangleFanSetNode *findTriangleFanSetNode(const char *name)
		{
			return (TriangleFanSetNode *)findNode(TRIANGLEFANSET_NODE, name);
		}
		
		TriangleStripSetNode *findTriangleStripSetNode(const char *name)
		{
			return (TriangleStripSetNode *)findNode(TRIANGLESTRIPSET_NODE, name);
		}
		
		// 12. Shape component (X3D)
		
		FillPropertiesNode *findFillPropertiesNode(const char *name)
		{
			return (FillPropertiesNode *)findNode(FILLPROPERTIES_NODE, name);
		}
		
		LinePropertiesNode *findLinePropertiesNode(const char *name)
		{
			return (LinePropertiesNode *)findNode(LINEPROPERTIES_NODE, name);
		}
		
		// 14. Geometry2D component (X3D)
		
		Arc2DNode *findArc2DNode(const char *name)
		{
			return (Arc2DNode *)findNode(ARC2D_NODE, name);
		}
		
		ArcClose2DNode *findArcClose2DNode(const char *name)
		{
			return (ArcClose2DNode *)findNode(ARCCLOSE2D_NODE, name);
		}
		
		Circle2DNode *findCircle2DNode(const char *name)
		{
			return (Circle2DNode *)findNode(CIRCLE2D_NODE, name);
		}
		
		Disk2DNode *findDisk2DNode(const char *name)
		{
			return (Disk2DNode *)findNode(DISK2D_NODE, name);
		}
		
		Polyline2DNode *findPolyline2DNode(const char *name)
		{
			return (Polyline2DNode *)findNode(POLYLINE2D_NODE, name);
		}
		
		Polypoint2DNode *findPolypoint2DNode(const char *name)
		{
			return (Polypoint2DNode *)findNode(POLYPOINT2D_NODE, name);
		}
		
		Rectangle2DNode *findRectangle2DNode(const char *name)
		{
			return (Rectangle2DNode *)findNode(RECTANGLE2D_NODE, name);
		}
		
		TriangleSet2DNode *findTriangleSet2DNode(const char *name)
		{
			return (TriangleSet2DNode *)findNode(TRIANGLESET2D_NODE, name);
		}
		
		// 18. Texturing component (x3D)
		
		MultiTextureNode *findMultiTextureNode(const char *name)
		{
			return (MultiTextureNode *)findNode(MULTITEXTURE_NODE, name);
		}
		
		MultiTextureCoordinateNode *findMultiTextureCoordinateNode(const char *name)
		{
			return (MultiTextureCoordinateNode *)findNode(MULTITEXTURECOORD_NODE, name);
		}
		
		MultiTextureTransformNode *findMultiTextureTransformNode(const char *name)
		{
			return (MultiTextureTransformNode *)findNode(MULTITEXTURETRANSFORM_NODE, name);
		}
		
		TextureCoordinateGeneratorNode *findTextureCoordinateGeneratorNode(const char *name)
		{
			return (TextureCoordinateGeneratorNode *)findNode(TEXCOORDGEN_NODE, name);
		}
		
		// 19. Interpolation component (X3D)
		
		CoordinateInterpolator2DNode *findCoordinateInterpolator2DNode(const char *name)
		{
			return (CoordinateInterpolator2DNode *)findNode(COORDINATEINTERPOLATOR2D_NODE, name);
		}
		
		PositionInterpolator2DNode *findPositionInterpolator2DNode(const char *name)
		{
			return (PositionInterpolator2DNode *)findNode(POSITIONINTERPOLATOR2D_NODE, name);
		}
		
		// 21. Key device sensor component (X3D)
		
		KeySensorNode *findKeySensorNode(const char *name)
		{
			return (KeySensorNode *)findNode(KEYSENSOR_NODE, name);
		}
		
		StringSensorNode *findStringSensorNode(const char *name)
		{
			return (StringSensorNode *)findNode(STRINGSENSOR_NODE, name);
		}
		
		// 30. Event Utilities component (X3D)
		
		BooleanFilterNode *findBooleanFilterNode(const char *name)
		{
			return (BooleanFilterNode *)findNode(BOOLEANFILTER_NODE, name);
		}
		
		BooleanToggleNode *findBooleanToggleNode(const char *name)
		{
			return (BooleanToggleNode *)findNode(BOOLEANTOGGLE_NODE, name);
		}
		
		BooleanTriggerNode *findBooleanTriggerNode(const char *name)
		{
			return (BooleanTriggerNode *)findNode(BOOLEANTRIGGER_NODE, name);
		}
		
		BooleanSequencerNode *findBooleanSequencerNode(const char *name)
		{
			return (BooleanSequencerNode *)findNode(BOOLEANSEQUENCER_NODE, name);
		}
		
		IntegerTriggerNode *findIntegerTriggerNode(const char *name)
		{
			return (IntegerTriggerNode *)findNode(INTEGERTRIGGER_NODE, name);
		}
		
		IntegerSequencerNode *findIntegerSequencerNode(const char *name)
		{
			return (IntegerSequencerNode *)findNode(INTEGERSEQUENCER_NODE, name);
		}
		
		TimeTriggerNode *findTimeTriggerNode(const char *name)
		{
			return (TimeTriggerNode *)findNode(TIMETRIGGER_NODE, name);
		}
		
		// Deprecated components (X3D)
		
		NodeSequencerNode *findNodeSequencerNode(const char *name)
		{
			return (NodeSequencerNode *)findNode(NODESEQUENCER_NODE, name);
		}
		
		Shape2DNode *findShape2DNode(const char *name)
		{
			return (Shape2DNode *)findNode(SHAPE2D_NODE, name);
		}
		
		BooleanTimeTriggerNode *findBooleanTimeTriggerNode(const char *name)
		{
			return (BooleanTimeTriggerNode *)findNode(BOOLEANTIMETRIGGER_NODE, name);
		}
		
		Transform2DNode *findTransform2DNode(const char *name)
		{
			return (Transform2DNode *)findNode(TRANSFORM2D_NODE, name);
		}
		
	};
	
}

#endif
