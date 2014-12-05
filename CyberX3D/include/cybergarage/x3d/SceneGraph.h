/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	SceneGraph.h
*
******************************************************************/

#ifndef _CX3D_SCENEGRAPH_H_
#define _CX3D_SCENEGRAPH_H_

#include <iostream>
#include <fstream>
#include <time.h>
#include <cybergarage/x3d/StringUtil.h>
#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/VRML97Nodes.h>
#include <cybergarage/x3d/X3DNodes.h>
#include <cybergarage/x3d/Scene.h>
#include <cybergarage/x3d/JavaVM.h>
#include <cybergarage/x3d/UrlFile.h>
#include <cybergarage/x3d/BoundingBox.h>
#include <cybergarage/x3d/RouteList.h>
#include <cybergarage/x3d/MathUtil.h>
#include <cybergarage/x3d/Parser.h>
#include <cybergarage/x3d/ParserResult.h>

namespace CyberX3D
{

	enum
	{
		SCENEGRAPH_OPTION_NONE			= 0x00,
		SCENEGRAPH_NORMAL_GENERATION	= 0x01,
		SCENEGRAPH_TEXTURE_GENERATION	= 0x02,
	};
	
#ifdef SUPPORT_JSAI
	class SceneGraph : public Scene, public JavaVM
	{
#else
	class SceneGraph : public Scene
	{
#endif
	
		int						mOption;
		
		Vector<BindableNode>	*mBackgroundNodeVector;
		Vector<BindableNode>	*mFogNodeVector;
		Vector<BindableNode>	*mNavigationInfoNodeVector;
		Vector<BindableNode>	*mViewpointNodeVector;
		
		ShapeNode				*mSelectedShapeNode;
		Node					*mSelectedNode;
		
		BackgroundNode			*mDefaultBackgroundNode;
		FogNode					*mDefaultFogNode;
		NavigationInfoNode		*mDefaultNavigationInfoNode;
		ViewpointNode			*mDefaultViewpointNode;
		
		float					mBoundingBoxSize[3];
		float					mBoundingBoxCenter[3];
		float					mFrameRate;
		
		ParserResult	mParserResult;
		
#ifdef SUPPORT_URL
		UrlFile					*mUrl;
#endif
		
	public:
	
		SceneGraph();
		
#ifdef SUPPORT_JSAI
		void setJavaEnv(const char *javaClassPath = NULL, jint(JNICALL *printfn)(FILE *fp, const char *format, va_list args) = NULL);
#endif
		
		~SceneGraph();
		
		////////////////////////////////////////////////
		//	Option
		////////////////////////////////////////////////
		
		void setOption(int option)
		{
			mOption = option;
		}
		
		int getOption()
		{
			return mOption;
		}
		
		////////////////////////////////////////////////
		//	child node list
		////////////////////////////////////////////////
		
		int getNAllNodes();
		int getNNodes();
		Node *getNodes(const int type);
		Node *getNodes();
		
		////////////////////////////////////////////////
		//	child node list
		////////////////////////////////////////////////
		
		GroupingNode *getGroupingNodes()
		{
			for(Node *node = getNodes(); node; node = node->next())
			{
				if(node->isGroupingNode())
					return (GroupingNode *)node;
			}
			return NULL;
		}
		
		AnchorNode *getAnchorNodes()
		{
			return (AnchorNode *)getNodes(ANCHOR_NODE);
		}
		
		AppearanceNode *getAppearanceNodes()
		{
			return (AppearanceNode *)getNodes(APPEARANCE_NODE);
		}
		
		AudioClipNode *getAudioClipNodes()
		{
			return (AudioClipNode *)getNodes(AUDIOCLIP_NODE);
		}
		
		BackgroundNode *getBackgroundNodes()
		{
			return (BackgroundNode *)getNodes(BACKGROUND_NODE);
		}
		
		BillboardNode *getBillboardNodes()
		{
			return (BillboardNode *)getNodes(BILLBOARD_NODE);
		}
		
		BoxNode *getBoxeNodes()
		{
			return (BoxNode *)getNodes(BOX_NODE);
		}
		
		CollisionNode *getCollisionNodes()
		{
			return (CollisionNode *)getNodes(COLLISION_NODE);
		}
		
		ColorNode *getColorNodes()
		{
			return (ColorNode *)getNodes(COLOR_NODE);
		}
		
		ColorInterpolatorNode *getColorInterpolatorNodes()
		{
			return (ColorInterpolatorNode *)getNodes(COLORINTERPOLATOR_NODE);
		}
		
		ConeNode *getConeNodes()
		{
			return (ConeNode *)getNodes(CONE_NODE);
		}
		
		CoordinateNode *getCoordinateNodes()
		{
			return (CoordinateNode *)getNodes(COORDINATE_NODE);
		}
		
		CoordinateInterpolatorNode *getCoordinateInterpolatorNodes()
		{
			return (CoordinateInterpolatorNode *)getNodes(COORDINATEINTERPOLATOR_NODE);
		}
		
		CylinderNode *getCylinderNodes()
		{
			return (CylinderNode *)getNodes(CYLINDER_NODE);
		}
		
		CylinderSensorNode *getCylinderSensorNodes()
		{
			return (CylinderSensorNode *)getNodes(CYLINDERSENSOR_NODE);
		}
		
		DirectionalLightNode *getDirectionalLightNodes()
		{
			return (DirectionalLightNode *)getNodes(DIRECTIONALLIGHT_NODE);
		}
		
		ElevationGridNode *getElevationGridNodes()
		{
			return (ElevationGridNode *)getNodes(ELEVATIONGRID_NODE);
		}
		
		ExtrusionNode *getExtrusionNodes()
		{
			return (ExtrusionNode *)getNodes(EXTRUSION_NODE);
		}
		
		FogNode *getFogNodes()
		{
			return (FogNode *)getNodes(FOG_NODE);
		}
		
		FontStyleNode *getFontStyleNodes()
		{
			return (FontStyleNode *)getNodes(FONTSTYLE_NODE);
		}
		
		GroupNode *getGroupNodes()
		{
			return (GroupNode *)getNodes(GROUP_NODE);
		}
		
		ImageTextureNode *getImageTextureNodes()
		{
			return (ImageTextureNode *)getNodes(IMAGETEXTURE_NODE);
		}
		
		IndexedFaceSetNode *getIndexedFaceSetNodes()
		{
			return (IndexedFaceSetNode *)getNodes(INDEXEDFACESET_NODE);
		}
		
		IndexedLineSetNode *getIndexedLineSetNodes()
		{
			return (IndexedLineSetNode *)getNodes(INDEXEDLINESET_NODE);
		}
		
		InlineNode *getInlineNodes()
		{
			return (InlineNode *)getNodes(INLINE_NODE);
		}
		
		LODNode *getLODNodes()
		{
			return (LODNode *)getNodes(LOD_NODE);
		}
		
		MaterialNode *getMaterialNodes()
		{
			return (MaterialNode *)getNodes(MATERIAL_NODE);
		}
		
		MovieTextureNode *getMovieTextureNodes()
		{
			return (MovieTextureNode *)getNodes(MOVIETEXTURE_NODE);
		}
		
		NavigationInfoNode *getNavigationInfoNodes()
		{
			return (NavigationInfoNode *)getNodes(NAVIGATIONINFO_NODE);
		}
		
		NormalNode *getNormalNodes()
		{
			return (NormalNode *)getNodes(NORMAL_NODE);
		}
		
		NormalInterpolatorNode *getNormalInterpolatorNodes()
		{
			return (NormalInterpolatorNode *)getNodes(NORMALINTERPOLATOR_NODE);
		}
		
		OrientationInterpolatorNode *getOrientationInterpolatorNodes()
		{
			return (OrientationInterpolatorNode *)getNodes(ORIENTATIONINTERPOLATOR_NODE);
		}
		
		PixelTextureNode *getPixelTextureNodes()
		{
			return (PixelTextureNode *)getNodes(PIXELTEXTURE_NODE);
		}
		
		PlaneSensorNode *getPlaneSensorNodes()
		{
			return (PlaneSensorNode *)getNodes(PLANESENSOR_NODE);
		}
		
		PointLightNode *getPointLightNodes()
		{
			return (PointLightNode *)getNodes(POINTLIGHT_NODE);
		}
		
		PointSetNode *getPointSetNodes()
		{
			return (PointSetNode *)getNodes(POINTSET_NODE);
		}
		
		PositionInterpolatorNode *getPositionInterpolatorNodes()
		{
			return (PositionInterpolatorNode *)getNodes(POSITIONINTERPOLATOR_NODE);
		}
		
		ProximitySensorNode *getProximitySensorNodes()
		{
			return (ProximitySensorNode *)getNodes(PROXIMITYSENSOR_NODE);
		}
		
		ScalarInterpolatorNode *getScalarInterpolatorNodes()
		{
			return (ScalarInterpolatorNode *)getNodes(SCALARINTERPOLATOR_NODE);
		}
		
		ScriptNode *getScriptNodes()
		{
			return (ScriptNode *)getNodes(SCRIPT_NODE);
		}
		
		ShapeNode *getShapeNodes()
		{
			return (ShapeNode *)getNodes(SHAPE_NODE);
		}
		
		SoundNode *getSoundNodes()
		{
			return (SoundNode *)getNodes(SOUND_NODE);
		}
		
		SphereNode *getSphereNodes()
		{
			return (SphereNode *)getNodes(SPHERE_NODE);
		}
		
		SphereSensorNode *getSphereSensorNodes()
		{
			return (SphereSensorNode *)getNodes(SPHERESENSOR_NODE);
		}
		
		SpotLightNode *getSpotLightNodes()
		{
			return (SpotLightNode *)getNodes(SPOTLIGHT_NODE);
		}
		
		SwitchNode *getSwitchNodes()
		{
			return (SwitchNode *)getNodes(SWITCH_NODE);
		}
		
		TextNode *getTextNodes()
		{
			return (TextNode *)getNodes(TEXT_NODE);
		}
		
		TextureCoordinateNode *getTextureCoordinateNodes()
		{
			return (TextureCoordinateNode *)getNodes(TEXTURECOORDINATE_NODE);
		}
		
		TextureTransformNode *getTextureTransformNodes()
		{
			return (TextureTransformNode *)getNodes(TEXTURETRANSFORM_NODE);
		}
		
		TimeSensorNode *getTimeSensorNodes()
		{
			return (TimeSensorNode *)getNodes(TIMESENSOR_NODE);
		}
		
		TouchSensorNode *getTouchSensorNodes()
		{
			return (TouchSensorNode *)getNodes(TOUCHSENSOR_NODE);
		}
		
		TransformNode *getTransformNodes()
		{
			return (TransformNode *)getNodes(TRANSFORM_NODE);
		}
		
		ViewpointNode *getViewpointNodes()
		{
			return (ViewpointNode *)getNodes(VIEWPOINT_NODE);
		}
		
		VisibilitySensorNode *getVisibilitySensorNodes()
		{
			return (VisibilitySensorNode *)getNodes(VISIBILITYSENSOR_NODE);
		}
		
		WorldInfoNode *getWorldInfoNodes()
		{
			return (WorldInfoNode *)getNodes(WORLDINFO_NODE);
		}
		
		// 9. Networking component (X3D)
		
		LoadSensorNode *getLoadSensorNodes()
		{
			return (LoadSensorNode *)getNodes(LOADSENSOR_NODE);
		}
		
		// 10. Grouping component (X3D)
		
		StaticGroupNode *getStaticGroupNodes()
		{
			return (StaticGroupNode *)getNodes(STATICGROUP_NODE);
		}
		
		// 11. Rendering component (X3D)
		
		ColorRGBANode *getColorRGBANodes()
		{
			return (ColorRGBANode *)getNodes(COLORRGBA_NODE);
		}
		
		TriangleSetNode *getTriangleSetNodes()
		{
			return (TriangleSetNode *)getNodes(TRIANGLESET_NODE);
		}
		
		TriangleFanSetNode *getTriangleFanSetNodes()
		{
			return (TriangleFanSetNode *)getNodes(TRIANGLEFANSET_NODE);
		}
		
		TriangleStripSetNode *getTriangleStripSetNodes()
		{
			return (TriangleStripSetNode *)getNodes(TRIANGLESTRIPSET_NODE);
		}
		
		// 12. Shape component (X3D)
		
		FillPropertiesNode *getFillPropertiesNodes()
		{
			return (FillPropertiesNode *)getNodes(FILLPROPERTIES_NODE);
		}
		
		LinePropertiesNode *getLinePropertiesNodes()
		{
			return (LinePropertiesNode *)getNodes(LINEPROPERTIES_NODE);
		}
		
		// 14. Geometry2D component (X3D)
		
		Arc2DNode *getArc2DNodes()
		{
			return (Arc2DNode *)getNodes(ARC2D_NODE);
		}
		
		ArcClose2DNode *getArcClose2DNodes()
		{
			return (ArcClose2DNode *)getNodes(ARCCLOSE2D_NODE);
		}
		
		Circle2DNode *getCircle2DNodes()
		{
			return (Circle2DNode *)getNodes(CIRCLE2D_NODE);
		}
		
		Disk2DNode *getDisk2DNodes()
		{
			return (Disk2DNode *)getNodes(DISK2D_NODE);
		}
		
		Polyline2DNode *getPolyline2DNodes()
		{
			return (Polyline2DNode *)getNodes(POLYLINE2D_NODE);
		}
		
		Polypoint2DNode *getPolypoint2DNodes()
		{
			return (Polypoint2DNode *)getNodes(POLYPOINT2D_NODE);
		}
		
		Rectangle2DNode *getRectangle2DNodes()
		{
			return (Rectangle2DNode *)getNodes(RECTANGLE2D_NODE);
		}
		
		TriangleSet2DNode *getTriangleSet2DNodes()
		{
			return (TriangleSet2DNode *)getNodes(TRIANGLESET2D_NODE);
		}
		
		// 18. Texturing component (x3D)
		
		MultiTextureNode *getMultiTextureNodes()
		{
			return (MultiTextureNode *)getNodes(MULTITEXTURE_NODE);
		}
		
		MultiTextureCoordinateNode *getMultiTextureCoordinateNodes()
		{
			return (MultiTextureCoordinateNode *)getNodes(MULTITEXTURECOORD_NODE);
		}
		
		MultiTextureTransformNode *getMultiTextureTransformNodes()
		{
			return (MultiTextureTransformNode *)getNodes(MULTITEXTURETRANSFORM_NODE);
		}
		
		TextureCoordinateGeneratorNode *getTextureCoordinateGeneratorNodes()
		{
			return (TextureCoordinateGeneratorNode *)getNodes(TEXCOORDGEN_NODE);
		}
		
		// 19. Interpolation component (X3D)
		
		CoordinateInterpolator2DNode *getCoordinateInterpolator2DNodes()
		{
			return (CoordinateInterpolator2DNode *)getNodes(COORDINATEINTERPOLATOR2D_NODE);
		}
		
		PositionInterpolator2DNode *getPositionInterpolator2DNodes()
		{
			return (PositionInterpolator2DNode *)getNodes(POSITIONINTERPOLATOR2D_NODE);
		}
		
		// 21. Key device sensor component (X3D)
		
		KeySensorNode *getKeySensorNodes()
		{
			return (KeySensorNode *)getNodes(KEYSENSOR_NODE);
		}
		
		StringSensorNode *getStringSensorNodes()
		{
			return (StringSensorNode *)getNodes(STRINGSENSOR_NODE);
		}
		
		// 30. Event Utilities component (X3D)
		
		BooleanFilterNode *getBooleanFilterNodes()
		{
			return (BooleanFilterNode *)getNodes(BOOLEANFILTER_NODE);
		}
		
		BooleanToggleNode *getBooleanToggleNodes()
		{
			return (BooleanToggleNode *)getNodes(BOOLEANTOGGLE_NODE);
		}
		
		BooleanTriggerNode *getBooleanTriggerNodes()
		{
			return (BooleanTriggerNode *)getNodes(BOOLEANTRIGGER_NODE);
		}
		
		BooleanSequencerNode *getBooleanSequencerNodes()
		{
			return (BooleanSequencerNode *)getNodes(BOOLEANSEQUENCER_NODE);
		}
		
		IntegerTriggerNode *getIntegerTriggerNodes()
		{
			return (IntegerTriggerNode *)getNodes(INTEGERTRIGGER_NODE);
		}
		
		IntegerSequencerNode *getIntegerSequencerNodes()
		{
			return (IntegerSequencerNode *)getNodes(INTEGERSEQUENCER_NODE);
		}
		
		TimeTriggerNode *getTimeTriggerNodes()
		{
			return (TimeTriggerNode *)getNodes(TIMETRIGGER_NODE);
		}
		
		// Deprecated components (X3D)
		
		NodeSequencerNode *getNodeSequencerNodes()
		{
			return (NodeSequencerNode *)getNodes(NODESEQUENCER_NODE);
		}
		
		Shape2DNode *getShape2DNodes()
		{
			return (Shape2DNode *)getNodes(SHAPE2D_NODE);
		}
		
		BooleanTimeTriggerNode *getBooleanTimeTriggerNodes()
		{
			return (BooleanTimeTriggerNode *)getNodes(BOOLEANTIMETRIGGER_NODE);
		}
		
		Transform2DNode *getTransform2DNodes()
		{
			return (Transform2DNode *)getNodes(TRANSFORM2D_NODE);
		}
		
		////////////////////////////////////////////////
		//	Node Number
		////////////////////////////////////////////////
		
		unsigned int getNodeNumber(Node *node) ;
		
		////////////////////////////////////////////////
		//	initialize
		////////////////////////////////////////////////
		
		void initialize(void (*callbackFn)(int nNode, void *info) = NULL, void *callbackFnInfo = NULL);
		
		void uninitialize(void (*callbackFn)(int nNode, void *info) = NULL, void *callbackFnInfo = NULL);
		
		////////////////////////////////////////////////
		//	update
		////////////////////////////////////////////////
		
		void update();
		void updateRoute(Node *eventOutNode, Field *eventOutField);
		
		///////////////////////////////////////////////
		//	Output node infomations
		///////////////////////////////////////////////
		
		void print();
		void printXML();
		
		///////////////////////////////////////////////
		//	Delete/Remove Node
		///////////////////////////////////////////////
		
		void removeNode(Node *node);
		void deleteNode(Node *node);
		
		///////////////////////////////////////////////
		//	Bindable Nodes
		///////////////////////////////////////////////
		
		void setBindableNode(Vector<BindableNode> *nodeVector, BindableNode *node, bool bind);
		
		void setBindableNode(BindableNode *node, bool bind);
		
		void setBackgroundNode(BackgroundNode *bg, bool bind)
		{
			setBindableNode(mBackgroundNodeVector, bg, bind);
		}
		
		void setFogNode(FogNode *fog, bool bind)
		{
			setBindableNode(mFogNodeVector, fog, bind);
		}
		
		void setNavigationInfoNode(NavigationInfoNode *navInfo, bool bind)
		{
			setBindableNode(mNavigationInfoNodeVector, navInfo, bind);
		}
		
		void setViewpointNode(ViewpointNode *view, bool bind)
		{
			setBindableNode(mViewpointNodeVector, view, bind);
		}
		
		BackgroundNode *getBackgroundNode()
		{
			return (BackgroundNode *)mBackgroundNodeVector->lastElement();
		}
		
		FogNode *getFogNode()
		{
			return (FogNode *)mFogNodeVector->lastElement();
		}
		
		NavigationInfoNode *getNavigationInfoNode()
		{
			return (NavigationInfoNode *)mNavigationInfoNodeVector->lastElement();
		}
		
		ViewpointNode *getViewpointNode()
		{
			return (ViewpointNode *)mViewpointNodeVector->lastElement();
		}
		
		////////////////////////////////////////////////
		//	BoundingBoxSize
		////////////////////////////////////////////////
		
		void setBoundingBoxSize(float value[]);
		void setBoundingBoxSize(float x, float y, float z);
		void getBoundingBoxSize(float value[]);
		
		////////////////////////////////////////////////
		//	BoundingBoxCenter
		////////////////////////////////////////////////
		
		void setBoundingBoxCenter(float value[]);
		void setBoundingBoxCenter(float x, float y, float z);
		void getBoundingBoxCenter(float value[]);
		
		////////////////////////////////////////////////
		//	BoundingBox
		////////////////////////////////////////////////
		
		void setBoundingBox(BoundingBox *bbox) ;
		void recomputeBoundingBox();
		
		////////////////////////////////////////////////
		//	Polygons
		////////////////////////////////////////////////
		
		int getNPolygons();
		
		///////////////////////////////////////////////
		//	Load
		///////////////////////////////////////////////
		
		void clear();
		
		bool load(const char *filename, bool bInitialize = true, void (*callbackFn)(int nLine, void *info) = NULL, void *callbackFnInfo = NULL);
		bool add(const char *filename, bool bInitialize = true, void (*callbackFn)(int nLine, void *info) = NULL, void *callbackFnInfo = NULL);
		
		///////////////////////////////////////////////
		//	Parser
		///////////////////////////////////////////////
		
		void moveParserNodes(Parser *parser);
		void moveParserRoutes(Parser *parser);
		
		ParserResult *getParserResult()
		{
			return &mParserResult;
		}
		
		int	getParserErrorLineNumber(void)
		{
			return getParserResult()->getErrorLineNumber();
		}
		
		char *getParserErrorMessage(void)
		{
			return getParserResult()->getErrorMessage();
		}
		
		char *getParserErrorToken(void)
		{
			return getParserResult()->getErrorToken();
		}
		
		char *getParserErrorLineString(void)
		{
			return getParserResult()->getErrorLineString();
		}
		
		///////////////////////////////////////////////
		//	Save node infomations
		///////////////////////////////////////////////
		
		bool save(const char *filename, void (*callbackFn)(int nNode, void *info) = NULL, void *callbackFnInfo = NULL);
		bool saveXML(const char *filename, void (*callbackFn)(int nNode, void *info) = NULL, void *callbackFnInfo = NULL);
		
		///////////////////////////////////////////////
		//	URL
		///////////////////////////////////////////////
		
#ifdef SUPPORT_URL
		
		void	setUrl(const char *url)
		{
			mUrl->setUrl(url);
		}
		char	*getUrl()
		{
			return mUrl->getUrl();
		}
		bool	getUrlStream(const char *urlStrnig)
		{
			return mUrl->getStream(urlStrnig);
		}
		char	*getUrlOutputFilename()
		{
			return mUrl->getOutputFilename();
		}
		bool	deleteUrlOutputFilename()
		{
			return mUrl->deleteOutputFilename();
		}
		
#endif
		
		//////////////////////////////////////////////////
		// Selected Shape/Node
		//////////////////////////////////////////////////
		
		void			setSelectedShapeNode(ShapeNode *shape)
		{
			mSelectedShapeNode = shape;
		}
		ShapeNode		*getSelectedShapeNode()
		{
			return mSelectedShapeNode;
		}
		
		void			setSelectedNode(Node *node)
		{
			mSelectedNode = node;
		}
		Node			*getSelectedNode()
		{
			return mSelectedNode;
		}
		
		//////////////////////////////////////////////////
		// Default Bindable Nodes
		//////////////////////////////////////////////////
		
		BackgroundNode		*getDefaultBackgroundNode()
		{
			return mDefaultBackgroundNode;
		}
		FogNode				*getDefaultFogNode()
		{
			return mDefaultFogNode;
		}
		NavigationInfoNode	*getDefaultNavigationInfoNode()
		{
			return mDefaultNavigationInfoNode;
		}
		ViewpointNode		*getDefaultViewpointNode()
		{
			return mDefaultViewpointNode;
		}
		
		//////////////////////////////////////////////////
		// Zoom All
		//////////////////////////////////////////////////
		
		void			zoomAllViewpoint();
		
		//////////////////////////////////////////////////
		// FrameRate
		//////////////////////////////////////////////////
		
		void setFrameRate(float value)
		{
			mFrameRate = value;
		}
		
		void addFrameRate(float value)
		{
			mFrameRate += value;
			mFrameRate /= 2.0;
		}
		
		void addFrameRateByTime(time_t value)
		{
			addFrameRate(1.0f / (value / 1000.0f));
		}
		
		float getFrameRate()
		{
			return mFrameRate;
		}
	};
	
}

#endif
