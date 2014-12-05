#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/AnchorNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/AppearanceNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Arc2DNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ArcClose2DNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/AudioClipNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BackgroundNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BillboardNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BindableNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BooleanFilterNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BooleanSequencerNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BooleanTimeTriggerNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BooleanToggleNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BooleanTriggerNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Bounded2DNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BoundedGrouping2DNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BoundedGroupingNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BoundedNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BoundingBox.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BoundingBox2D.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BoxNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Circle2DNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/CollisionNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ColorInterpolatorNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ColorNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ColorRGBANode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ComposedGeometryNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ConeNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/CoordinateInterpolator2DNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/CoordinateInterpolatorNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/CoordinateNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/CylinderNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/CylinderSensorNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/DEF.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/DEFNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/DirectionalLightNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Disk2DNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/DragSensorNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ElevationGridNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/EnvironmentalSensorNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Event.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ExtrusionNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Field.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/FileGIF89a.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/FileImage.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/FileJPEG.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/FilePNG.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/FileTarga.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/FileUtil.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/FillPropertiesNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/FogNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/FontStyleNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Geometry2DNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Geometry3DNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/GeometryNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/GroupNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Grouping2DNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/GroupingNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ImageTextureNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/IndexedFaceSetNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/IndexedLineSetNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/InlineNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/IntegerSequencerNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/IntegerTriggerNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/InterpolatorNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/JNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/JScript.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/JavaVM.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/KeyDeviceSensorNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/KeySensorNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/LODNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/LightNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/LinePropertiesNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/LoadSensorNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFBool.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFChar.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFColor.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFColorRGBA.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFDouble.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFFloat.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFInt32.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFRotation.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFString.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFTime.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFVec2d.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFVec2f.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFVec3d.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFVec3f.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MField.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MaterialNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MathUtil.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MovieTextureNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MultiTextureCoordinateNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MultiTextureNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MultiTextureTransformNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/NavigationInfoNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/NetworkSensorNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Node.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/NodeList.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/NodeSequencerNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/NodeType.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/NormalInterpolatorNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/NormalNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/OrientationInterpolatorNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/PROTO.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Parser.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ParserFunc.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ParserNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/PixelTextureNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/PlaneSensorNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/PointLightNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/PointSetNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Polyline2DNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Polypoint2DNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/PositionInterpolator2DNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/PositionInterpolatorNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ProximitySensorNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Rectangle2DNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/RootNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Route.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/RouteList.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/RouteNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFBool.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFChar.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFColor.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFColorRGBA.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFDouble.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFFloat.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFImage.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFInt32.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFMatrix.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFRotation.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFString.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFTime.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFVec2d.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFVec2f.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFVec3d.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFVec3f.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ScalarInterpolatorNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Scene.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SceneGraph.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SceneNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ScriptNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SensorNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SequencerNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Shape2DNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ShapeNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SoundNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SoundSourceNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SphereNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SphereSensorNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SpotLightNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/StaticGroupNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/StringSensorNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/StringUtil.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SwitchNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TextNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Texture2DNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TextureCoordinateGeneratorNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TextureCoordinateNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TextureNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TextureTransformNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TimeSensorNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TimeTriggerNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TouchSensorNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Transform2DNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TransformNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TriangleFanSetNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TriangleSet2DNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TriangleSetNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TriangleStripSetNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TriggerNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/UrlFile.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/VRML97.tab.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/VRML97.yy.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/VRML97Parser.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/VRML97ParserFunc.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ViewpointNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/VisibilitySensorNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/WorldInfoNode.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/X3DParser.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/X3DParserHandlers.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/X3DParserTokenizer.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/XMLElement.o \
	${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/XMLNode.o \
	${OBJECTDIR}/PQP_v1.3/src/BV.o \
	${OBJECTDIR}/PQP_v1.3/src/Build.o \
	${OBJECTDIR}/PQP_v1.3/src/PQP.o \
	${OBJECTDIR}/PQP_v1.3/src/TriDist.o \
	${OBJECTDIR}/gProximity/Matrix.o \
	${OBJECTDIR}/gProximity/cpu_bvh_constru.o \
	${OBJECTDIR}/gProximity/cuda_make_grid.o \
	${OBJECTDIR}/gProximity/cuda_timer.o \
	${OBJECTDIR}/gProximity/geometry.o \
	${OBJECTDIR}/gProximity/importer_utility.o \
	${OBJECTDIR}/gProximity/main.o \
	${OBJECTDIR}/gProximity/plyfile.o \
	${OBJECTDIR}/gProximity/plyfunctions.o \
	${OBJECTDIR}/gProximity/radixsort.o \
	${OBJECTDIR}/gProximity/scene.o \
	${OBJECTDIR}/gProximity/transform.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gproximity

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gproximity: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gproximity ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/AnchorNode.o: CyberX3D/src/cybergarage/x3d/AnchorNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/AnchorNode.o CyberX3D/src/cybergarage/x3d/AnchorNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/AppearanceNode.o: CyberX3D/src/cybergarage/x3d/AppearanceNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/AppearanceNode.o CyberX3D/src/cybergarage/x3d/AppearanceNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Arc2DNode.o: CyberX3D/src/cybergarage/x3d/Arc2DNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Arc2DNode.o CyberX3D/src/cybergarage/x3d/Arc2DNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ArcClose2DNode.o: CyberX3D/src/cybergarage/x3d/ArcClose2DNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ArcClose2DNode.o CyberX3D/src/cybergarage/x3d/ArcClose2DNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/AudioClipNode.o: CyberX3D/src/cybergarage/x3d/AudioClipNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/AudioClipNode.o CyberX3D/src/cybergarage/x3d/AudioClipNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BackgroundNode.o: CyberX3D/src/cybergarage/x3d/BackgroundNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BackgroundNode.o CyberX3D/src/cybergarage/x3d/BackgroundNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BillboardNode.o: CyberX3D/src/cybergarage/x3d/BillboardNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BillboardNode.o CyberX3D/src/cybergarage/x3d/BillboardNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BindableNode.o: CyberX3D/src/cybergarage/x3d/BindableNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BindableNode.o CyberX3D/src/cybergarage/x3d/BindableNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BooleanFilterNode.o: CyberX3D/src/cybergarage/x3d/BooleanFilterNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BooleanFilterNode.o CyberX3D/src/cybergarage/x3d/BooleanFilterNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BooleanSequencerNode.o: CyberX3D/src/cybergarage/x3d/BooleanSequencerNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BooleanSequencerNode.o CyberX3D/src/cybergarage/x3d/BooleanSequencerNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BooleanTimeTriggerNode.o: CyberX3D/src/cybergarage/x3d/BooleanTimeTriggerNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BooleanTimeTriggerNode.o CyberX3D/src/cybergarage/x3d/BooleanTimeTriggerNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BooleanToggleNode.o: CyberX3D/src/cybergarage/x3d/BooleanToggleNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BooleanToggleNode.o CyberX3D/src/cybergarage/x3d/BooleanToggleNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BooleanTriggerNode.o: CyberX3D/src/cybergarage/x3d/BooleanTriggerNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BooleanTriggerNode.o CyberX3D/src/cybergarage/x3d/BooleanTriggerNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Bounded2DNode.o: CyberX3D/src/cybergarage/x3d/Bounded2DNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Bounded2DNode.o CyberX3D/src/cybergarage/x3d/Bounded2DNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BoundedGrouping2DNode.o: CyberX3D/src/cybergarage/x3d/BoundedGrouping2DNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BoundedGrouping2DNode.o CyberX3D/src/cybergarage/x3d/BoundedGrouping2DNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BoundedGroupingNode.o: CyberX3D/src/cybergarage/x3d/BoundedGroupingNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BoundedGroupingNode.o CyberX3D/src/cybergarage/x3d/BoundedGroupingNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BoundedNode.o: CyberX3D/src/cybergarage/x3d/BoundedNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BoundedNode.o CyberX3D/src/cybergarage/x3d/BoundedNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BoundingBox.o: CyberX3D/src/cybergarage/x3d/BoundingBox.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BoundingBox.o CyberX3D/src/cybergarage/x3d/BoundingBox.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BoundingBox2D.o: CyberX3D/src/cybergarage/x3d/BoundingBox2D.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BoundingBox2D.o CyberX3D/src/cybergarage/x3d/BoundingBox2D.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BoxNode.o: CyberX3D/src/cybergarage/x3d/BoxNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/BoxNode.o CyberX3D/src/cybergarage/x3d/BoxNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Circle2DNode.o: CyberX3D/src/cybergarage/x3d/Circle2DNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Circle2DNode.o CyberX3D/src/cybergarage/x3d/Circle2DNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/CollisionNode.o: CyberX3D/src/cybergarage/x3d/CollisionNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/CollisionNode.o CyberX3D/src/cybergarage/x3d/CollisionNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ColorInterpolatorNode.o: CyberX3D/src/cybergarage/x3d/ColorInterpolatorNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ColorInterpolatorNode.o CyberX3D/src/cybergarage/x3d/ColorInterpolatorNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ColorNode.o: CyberX3D/src/cybergarage/x3d/ColorNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ColorNode.o CyberX3D/src/cybergarage/x3d/ColorNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ColorRGBANode.o: CyberX3D/src/cybergarage/x3d/ColorRGBANode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ColorRGBANode.o CyberX3D/src/cybergarage/x3d/ColorRGBANode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ComposedGeometryNode.o: CyberX3D/src/cybergarage/x3d/ComposedGeometryNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ComposedGeometryNode.o CyberX3D/src/cybergarage/x3d/ComposedGeometryNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ConeNode.o: CyberX3D/src/cybergarage/x3d/ConeNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ConeNode.o CyberX3D/src/cybergarage/x3d/ConeNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/CoordinateInterpolator2DNode.o: CyberX3D/src/cybergarage/x3d/CoordinateInterpolator2DNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/CoordinateInterpolator2DNode.o CyberX3D/src/cybergarage/x3d/CoordinateInterpolator2DNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/CoordinateInterpolatorNode.o: CyberX3D/src/cybergarage/x3d/CoordinateInterpolatorNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/CoordinateInterpolatorNode.o CyberX3D/src/cybergarage/x3d/CoordinateInterpolatorNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/CoordinateNode.o: CyberX3D/src/cybergarage/x3d/CoordinateNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/CoordinateNode.o CyberX3D/src/cybergarage/x3d/CoordinateNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/CylinderNode.o: CyberX3D/src/cybergarage/x3d/CylinderNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/CylinderNode.o CyberX3D/src/cybergarage/x3d/CylinderNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/CylinderSensorNode.o: CyberX3D/src/cybergarage/x3d/CylinderSensorNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/CylinderSensorNode.o CyberX3D/src/cybergarage/x3d/CylinderSensorNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/DEF.o: CyberX3D/src/cybergarage/x3d/DEF.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/DEF.o CyberX3D/src/cybergarage/x3d/DEF.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/DEFNode.o: CyberX3D/src/cybergarage/x3d/DEFNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/DEFNode.o CyberX3D/src/cybergarage/x3d/DEFNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/DirectionalLightNode.o: CyberX3D/src/cybergarage/x3d/DirectionalLightNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/DirectionalLightNode.o CyberX3D/src/cybergarage/x3d/DirectionalLightNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Disk2DNode.o: CyberX3D/src/cybergarage/x3d/Disk2DNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Disk2DNode.o CyberX3D/src/cybergarage/x3d/Disk2DNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/DragSensorNode.o: CyberX3D/src/cybergarage/x3d/DragSensorNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/DragSensorNode.o CyberX3D/src/cybergarage/x3d/DragSensorNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ElevationGridNode.o: CyberX3D/src/cybergarage/x3d/ElevationGridNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ElevationGridNode.o CyberX3D/src/cybergarage/x3d/ElevationGridNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/EnvironmentalSensorNode.o: CyberX3D/src/cybergarage/x3d/EnvironmentalSensorNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/EnvironmentalSensorNode.o CyberX3D/src/cybergarage/x3d/EnvironmentalSensorNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Event.o: CyberX3D/src/cybergarage/x3d/Event.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Event.o CyberX3D/src/cybergarage/x3d/Event.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ExtrusionNode.o: CyberX3D/src/cybergarage/x3d/ExtrusionNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ExtrusionNode.o CyberX3D/src/cybergarage/x3d/ExtrusionNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Field.o: CyberX3D/src/cybergarage/x3d/Field.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Field.o CyberX3D/src/cybergarage/x3d/Field.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/FileGIF89a.o: CyberX3D/src/cybergarage/x3d/FileGIF89a.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/FileGIF89a.o CyberX3D/src/cybergarage/x3d/FileGIF89a.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/FileImage.o: CyberX3D/src/cybergarage/x3d/FileImage.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/FileImage.o CyberX3D/src/cybergarage/x3d/FileImage.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/FileJPEG.o: CyberX3D/src/cybergarage/x3d/FileJPEG.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/FileJPEG.o CyberX3D/src/cybergarage/x3d/FileJPEG.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/FilePNG.o: CyberX3D/src/cybergarage/x3d/FilePNG.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/FilePNG.o CyberX3D/src/cybergarage/x3d/FilePNG.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/FileTarga.o: CyberX3D/src/cybergarage/x3d/FileTarga.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/FileTarga.o CyberX3D/src/cybergarage/x3d/FileTarga.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/FileUtil.o: CyberX3D/src/cybergarage/x3d/FileUtil.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/FileUtil.o CyberX3D/src/cybergarage/x3d/FileUtil.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/FillPropertiesNode.o: CyberX3D/src/cybergarage/x3d/FillPropertiesNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/FillPropertiesNode.o CyberX3D/src/cybergarage/x3d/FillPropertiesNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/FogNode.o: CyberX3D/src/cybergarage/x3d/FogNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/FogNode.o CyberX3D/src/cybergarage/x3d/FogNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/FontStyleNode.o: CyberX3D/src/cybergarage/x3d/FontStyleNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/FontStyleNode.o CyberX3D/src/cybergarage/x3d/FontStyleNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Geometry2DNode.o: CyberX3D/src/cybergarage/x3d/Geometry2DNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Geometry2DNode.o CyberX3D/src/cybergarage/x3d/Geometry2DNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Geometry3DNode.o: CyberX3D/src/cybergarage/x3d/Geometry3DNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Geometry3DNode.o CyberX3D/src/cybergarage/x3d/Geometry3DNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/GeometryNode.o: CyberX3D/src/cybergarage/x3d/GeometryNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/GeometryNode.o CyberX3D/src/cybergarage/x3d/GeometryNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/GroupNode.o: CyberX3D/src/cybergarage/x3d/GroupNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/GroupNode.o CyberX3D/src/cybergarage/x3d/GroupNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Grouping2DNode.o: CyberX3D/src/cybergarage/x3d/Grouping2DNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Grouping2DNode.o CyberX3D/src/cybergarage/x3d/Grouping2DNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/GroupingNode.o: CyberX3D/src/cybergarage/x3d/GroupingNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/GroupingNode.o CyberX3D/src/cybergarage/x3d/GroupingNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ImageTextureNode.o: CyberX3D/src/cybergarage/x3d/ImageTextureNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ImageTextureNode.o CyberX3D/src/cybergarage/x3d/ImageTextureNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/IndexedFaceSetNode.o: CyberX3D/src/cybergarage/x3d/IndexedFaceSetNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/IndexedFaceSetNode.o CyberX3D/src/cybergarage/x3d/IndexedFaceSetNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/IndexedLineSetNode.o: CyberX3D/src/cybergarage/x3d/IndexedLineSetNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/IndexedLineSetNode.o CyberX3D/src/cybergarage/x3d/IndexedLineSetNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/InlineNode.o: CyberX3D/src/cybergarage/x3d/InlineNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/InlineNode.o CyberX3D/src/cybergarage/x3d/InlineNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/IntegerSequencerNode.o: CyberX3D/src/cybergarage/x3d/IntegerSequencerNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/IntegerSequencerNode.o CyberX3D/src/cybergarage/x3d/IntegerSequencerNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/IntegerTriggerNode.o: CyberX3D/src/cybergarage/x3d/IntegerTriggerNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/IntegerTriggerNode.o CyberX3D/src/cybergarage/x3d/IntegerTriggerNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/InterpolatorNode.o: CyberX3D/src/cybergarage/x3d/InterpolatorNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/InterpolatorNode.o CyberX3D/src/cybergarage/x3d/InterpolatorNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/JNode.o: CyberX3D/src/cybergarage/x3d/JNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/JNode.o CyberX3D/src/cybergarage/x3d/JNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/JScript.o: CyberX3D/src/cybergarage/x3d/JScript.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/JScript.o CyberX3D/src/cybergarage/x3d/JScript.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/JavaVM.o: CyberX3D/src/cybergarage/x3d/JavaVM.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/JavaVM.o CyberX3D/src/cybergarage/x3d/JavaVM.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/KeyDeviceSensorNode.o: CyberX3D/src/cybergarage/x3d/KeyDeviceSensorNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/KeyDeviceSensorNode.o CyberX3D/src/cybergarage/x3d/KeyDeviceSensorNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/KeySensorNode.o: CyberX3D/src/cybergarage/x3d/KeySensorNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/KeySensorNode.o CyberX3D/src/cybergarage/x3d/KeySensorNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/LODNode.o: CyberX3D/src/cybergarage/x3d/LODNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/LODNode.o CyberX3D/src/cybergarage/x3d/LODNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/LightNode.o: CyberX3D/src/cybergarage/x3d/LightNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/LightNode.o CyberX3D/src/cybergarage/x3d/LightNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/LinePropertiesNode.o: CyberX3D/src/cybergarage/x3d/LinePropertiesNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/LinePropertiesNode.o CyberX3D/src/cybergarage/x3d/LinePropertiesNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/LoadSensorNode.o: CyberX3D/src/cybergarage/x3d/LoadSensorNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/LoadSensorNode.o CyberX3D/src/cybergarage/x3d/LoadSensorNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFBool.o: CyberX3D/src/cybergarage/x3d/MFBool.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFBool.o CyberX3D/src/cybergarage/x3d/MFBool.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFChar.o: CyberX3D/src/cybergarage/x3d/MFChar.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFChar.o CyberX3D/src/cybergarage/x3d/MFChar.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFColor.o: CyberX3D/src/cybergarage/x3d/MFColor.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFColor.o CyberX3D/src/cybergarage/x3d/MFColor.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFColorRGBA.o: CyberX3D/src/cybergarage/x3d/MFColorRGBA.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFColorRGBA.o CyberX3D/src/cybergarage/x3d/MFColorRGBA.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFDouble.o: CyberX3D/src/cybergarage/x3d/MFDouble.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFDouble.o CyberX3D/src/cybergarage/x3d/MFDouble.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFFloat.o: CyberX3D/src/cybergarage/x3d/MFFloat.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFFloat.o CyberX3D/src/cybergarage/x3d/MFFloat.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFInt32.o: CyberX3D/src/cybergarage/x3d/MFInt32.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFInt32.o CyberX3D/src/cybergarage/x3d/MFInt32.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFNode.o: CyberX3D/src/cybergarage/x3d/MFNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFNode.o CyberX3D/src/cybergarage/x3d/MFNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFRotation.o: CyberX3D/src/cybergarage/x3d/MFRotation.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFRotation.o CyberX3D/src/cybergarage/x3d/MFRotation.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFString.o: CyberX3D/src/cybergarage/x3d/MFString.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFString.o CyberX3D/src/cybergarage/x3d/MFString.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFTime.o: CyberX3D/src/cybergarage/x3d/MFTime.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFTime.o CyberX3D/src/cybergarage/x3d/MFTime.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFVec2d.o: CyberX3D/src/cybergarage/x3d/MFVec2d.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFVec2d.o CyberX3D/src/cybergarage/x3d/MFVec2d.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFVec2f.o: CyberX3D/src/cybergarage/x3d/MFVec2f.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFVec2f.o CyberX3D/src/cybergarage/x3d/MFVec2f.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFVec3d.o: CyberX3D/src/cybergarage/x3d/MFVec3d.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFVec3d.o CyberX3D/src/cybergarage/x3d/MFVec3d.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFVec3f.o: CyberX3D/src/cybergarage/x3d/MFVec3f.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MFVec3f.o CyberX3D/src/cybergarage/x3d/MFVec3f.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MField.o: CyberX3D/src/cybergarage/x3d/MField.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MField.o CyberX3D/src/cybergarage/x3d/MField.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MaterialNode.o: CyberX3D/src/cybergarage/x3d/MaterialNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MaterialNode.o CyberX3D/src/cybergarage/x3d/MaterialNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MathUtil.o: CyberX3D/src/cybergarage/x3d/MathUtil.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MathUtil.o CyberX3D/src/cybergarage/x3d/MathUtil.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MovieTextureNode.o: CyberX3D/src/cybergarage/x3d/MovieTextureNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MovieTextureNode.o CyberX3D/src/cybergarage/x3d/MovieTextureNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MultiTextureCoordinateNode.o: CyberX3D/src/cybergarage/x3d/MultiTextureCoordinateNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MultiTextureCoordinateNode.o CyberX3D/src/cybergarage/x3d/MultiTextureCoordinateNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MultiTextureNode.o: CyberX3D/src/cybergarage/x3d/MultiTextureNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MultiTextureNode.o CyberX3D/src/cybergarage/x3d/MultiTextureNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MultiTextureTransformNode.o: CyberX3D/src/cybergarage/x3d/MultiTextureTransformNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/MultiTextureTransformNode.o CyberX3D/src/cybergarage/x3d/MultiTextureTransformNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/NavigationInfoNode.o: CyberX3D/src/cybergarage/x3d/NavigationInfoNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/NavigationInfoNode.o CyberX3D/src/cybergarage/x3d/NavigationInfoNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/NetworkSensorNode.o: CyberX3D/src/cybergarage/x3d/NetworkSensorNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/NetworkSensorNode.o CyberX3D/src/cybergarage/x3d/NetworkSensorNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Node.o: CyberX3D/src/cybergarage/x3d/Node.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Node.o CyberX3D/src/cybergarage/x3d/Node.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/NodeList.o: CyberX3D/src/cybergarage/x3d/NodeList.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/NodeList.o CyberX3D/src/cybergarage/x3d/NodeList.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/NodeSequencerNode.o: CyberX3D/src/cybergarage/x3d/NodeSequencerNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/NodeSequencerNode.o CyberX3D/src/cybergarage/x3d/NodeSequencerNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/NodeType.o: CyberX3D/src/cybergarage/x3d/NodeType.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/NodeType.o CyberX3D/src/cybergarage/x3d/NodeType.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/NormalInterpolatorNode.o: CyberX3D/src/cybergarage/x3d/NormalInterpolatorNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/NormalInterpolatorNode.o CyberX3D/src/cybergarage/x3d/NormalInterpolatorNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/NormalNode.o: CyberX3D/src/cybergarage/x3d/NormalNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/NormalNode.o CyberX3D/src/cybergarage/x3d/NormalNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/OrientationInterpolatorNode.o: CyberX3D/src/cybergarage/x3d/OrientationInterpolatorNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/OrientationInterpolatorNode.o CyberX3D/src/cybergarage/x3d/OrientationInterpolatorNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/PROTO.o: CyberX3D/src/cybergarage/x3d/PROTO.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/PROTO.o CyberX3D/src/cybergarage/x3d/PROTO.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Parser.o: CyberX3D/src/cybergarage/x3d/Parser.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Parser.o CyberX3D/src/cybergarage/x3d/Parser.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ParserFunc.o: CyberX3D/src/cybergarage/x3d/ParserFunc.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ParserFunc.o CyberX3D/src/cybergarage/x3d/ParserFunc.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ParserNode.o: CyberX3D/src/cybergarage/x3d/ParserNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ParserNode.o CyberX3D/src/cybergarage/x3d/ParserNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/PixelTextureNode.o: CyberX3D/src/cybergarage/x3d/PixelTextureNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/PixelTextureNode.o CyberX3D/src/cybergarage/x3d/PixelTextureNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/PlaneSensorNode.o: CyberX3D/src/cybergarage/x3d/PlaneSensorNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/PlaneSensorNode.o CyberX3D/src/cybergarage/x3d/PlaneSensorNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/PointLightNode.o: CyberX3D/src/cybergarage/x3d/PointLightNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/PointLightNode.o CyberX3D/src/cybergarage/x3d/PointLightNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/PointSetNode.o: CyberX3D/src/cybergarage/x3d/PointSetNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/PointSetNode.o CyberX3D/src/cybergarage/x3d/PointSetNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Polyline2DNode.o: CyberX3D/src/cybergarage/x3d/Polyline2DNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Polyline2DNode.o CyberX3D/src/cybergarage/x3d/Polyline2DNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Polypoint2DNode.o: CyberX3D/src/cybergarage/x3d/Polypoint2DNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Polypoint2DNode.o CyberX3D/src/cybergarage/x3d/Polypoint2DNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/PositionInterpolator2DNode.o: CyberX3D/src/cybergarage/x3d/PositionInterpolator2DNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/PositionInterpolator2DNode.o CyberX3D/src/cybergarage/x3d/PositionInterpolator2DNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/PositionInterpolatorNode.o: CyberX3D/src/cybergarage/x3d/PositionInterpolatorNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/PositionInterpolatorNode.o CyberX3D/src/cybergarage/x3d/PositionInterpolatorNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ProximitySensorNode.o: CyberX3D/src/cybergarage/x3d/ProximitySensorNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ProximitySensorNode.o CyberX3D/src/cybergarage/x3d/ProximitySensorNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Rectangle2DNode.o: CyberX3D/src/cybergarage/x3d/Rectangle2DNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Rectangle2DNode.o CyberX3D/src/cybergarage/x3d/Rectangle2DNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/RootNode.o: CyberX3D/src/cybergarage/x3d/RootNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/RootNode.o CyberX3D/src/cybergarage/x3d/RootNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Route.o: CyberX3D/src/cybergarage/x3d/Route.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Route.o CyberX3D/src/cybergarage/x3d/Route.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/RouteList.o: CyberX3D/src/cybergarage/x3d/RouteList.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/RouteList.o CyberX3D/src/cybergarage/x3d/RouteList.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/RouteNode.o: CyberX3D/src/cybergarage/x3d/RouteNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/RouteNode.o CyberX3D/src/cybergarage/x3d/RouteNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFBool.o: CyberX3D/src/cybergarage/x3d/SFBool.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFBool.o CyberX3D/src/cybergarage/x3d/SFBool.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFChar.o: CyberX3D/src/cybergarage/x3d/SFChar.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFChar.o CyberX3D/src/cybergarage/x3d/SFChar.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFColor.o: CyberX3D/src/cybergarage/x3d/SFColor.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFColor.o CyberX3D/src/cybergarage/x3d/SFColor.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFColorRGBA.o: CyberX3D/src/cybergarage/x3d/SFColorRGBA.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFColorRGBA.o CyberX3D/src/cybergarage/x3d/SFColorRGBA.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFDouble.o: CyberX3D/src/cybergarage/x3d/SFDouble.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFDouble.o CyberX3D/src/cybergarage/x3d/SFDouble.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFFloat.o: CyberX3D/src/cybergarage/x3d/SFFloat.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFFloat.o CyberX3D/src/cybergarage/x3d/SFFloat.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFImage.o: CyberX3D/src/cybergarage/x3d/SFImage.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFImage.o CyberX3D/src/cybergarage/x3d/SFImage.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFInt32.o: CyberX3D/src/cybergarage/x3d/SFInt32.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFInt32.o CyberX3D/src/cybergarage/x3d/SFInt32.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFMatrix.o: CyberX3D/src/cybergarage/x3d/SFMatrix.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFMatrix.o CyberX3D/src/cybergarage/x3d/SFMatrix.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFNode.o: CyberX3D/src/cybergarage/x3d/SFNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFNode.o CyberX3D/src/cybergarage/x3d/SFNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFRotation.o: CyberX3D/src/cybergarage/x3d/SFRotation.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFRotation.o CyberX3D/src/cybergarage/x3d/SFRotation.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFString.o: CyberX3D/src/cybergarage/x3d/SFString.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFString.o CyberX3D/src/cybergarage/x3d/SFString.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFTime.o: CyberX3D/src/cybergarage/x3d/SFTime.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFTime.o CyberX3D/src/cybergarage/x3d/SFTime.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFVec2d.o: CyberX3D/src/cybergarage/x3d/SFVec2d.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFVec2d.o CyberX3D/src/cybergarage/x3d/SFVec2d.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFVec2f.o: CyberX3D/src/cybergarage/x3d/SFVec2f.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFVec2f.o CyberX3D/src/cybergarage/x3d/SFVec2f.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFVec3d.o: CyberX3D/src/cybergarage/x3d/SFVec3d.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFVec3d.o CyberX3D/src/cybergarage/x3d/SFVec3d.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFVec3f.o: CyberX3D/src/cybergarage/x3d/SFVec3f.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SFVec3f.o CyberX3D/src/cybergarage/x3d/SFVec3f.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ScalarInterpolatorNode.o: CyberX3D/src/cybergarage/x3d/ScalarInterpolatorNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ScalarInterpolatorNode.o CyberX3D/src/cybergarage/x3d/ScalarInterpolatorNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Scene.o: CyberX3D/src/cybergarage/x3d/Scene.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Scene.o CyberX3D/src/cybergarage/x3d/Scene.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SceneGraph.o: CyberX3D/src/cybergarage/x3d/SceneGraph.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SceneGraph.o CyberX3D/src/cybergarage/x3d/SceneGraph.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SceneNode.o: CyberX3D/src/cybergarage/x3d/SceneNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SceneNode.o CyberX3D/src/cybergarage/x3d/SceneNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ScriptNode.o: CyberX3D/src/cybergarage/x3d/ScriptNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ScriptNode.o CyberX3D/src/cybergarage/x3d/ScriptNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SensorNode.o: CyberX3D/src/cybergarage/x3d/SensorNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SensorNode.o CyberX3D/src/cybergarage/x3d/SensorNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SequencerNode.o: CyberX3D/src/cybergarage/x3d/SequencerNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SequencerNode.o CyberX3D/src/cybergarage/x3d/SequencerNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Shape2DNode.o: CyberX3D/src/cybergarage/x3d/Shape2DNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Shape2DNode.o CyberX3D/src/cybergarage/x3d/Shape2DNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ShapeNode.o: CyberX3D/src/cybergarage/x3d/ShapeNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ShapeNode.o CyberX3D/src/cybergarage/x3d/ShapeNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SoundNode.o: CyberX3D/src/cybergarage/x3d/SoundNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SoundNode.o CyberX3D/src/cybergarage/x3d/SoundNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SoundSourceNode.o: CyberX3D/src/cybergarage/x3d/SoundSourceNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SoundSourceNode.o CyberX3D/src/cybergarage/x3d/SoundSourceNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SphereNode.o: CyberX3D/src/cybergarage/x3d/SphereNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SphereNode.o CyberX3D/src/cybergarage/x3d/SphereNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SphereSensorNode.o: CyberX3D/src/cybergarage/x3d/SphereSensorNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SphereSensorNode.o CyberX3D/src/cybergarage/x3d/SphereSensorNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SpotLightNode.o: CyberX3D/src/cybergarage/x3d/SpotLightNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SpotLightNode.o CyberX3D/src/cybergarage/x3d/SpotLightNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/StaticGroupNode.o: CyberX3D/src/cybergarage/x3d/StaticGroupNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/StaticGroupNode.o CyberX3D/src/cybergarage/x3d/StaticGroupNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/StringSensorNode.o: CyberX3D/src/cybergarage/x3d/StringSensorNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/StringSensorNode.o CyberX3D/src/cybergarage/x3d/StringSensorNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/StringUtil.o: CyberX3D/src/cybergarage/x3d/StringUtil.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/StringUtil.o CyberX3D/src/cybergarage/x3d/StringUtil.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SwitchNode.o: CyberX3D/src/cybergarage/x3d/SwitchNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/SwitchNode.o CyberX3D/src/cybergarage/x3d/SwitchNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TextNode.o: CyberX3D/src/cybergarage/x3d/TextNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TextNode.o CyberX3D/src/cybergarage/x3d/TextNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Texture2DNode.o: CyberX3D/src/cybergarage/x3d/Texture2DNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Texture2DNode.o CyberX3D/src/cybergarage/x3d/Texture2DNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TextureCoordinateGeneratorNode.o: CyberX3D/src/cybergarage/x3d/TextureCoordinateGeneratorNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TextureCoordinateGeneratorNode.o CyberX3D/src/cybergarage/x3d/TextureCoordinateGeneratorNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TextureCoordinateNode.o: CyberX3D/src/cybergarage/x3d/TextureCoordinateNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TextureCoordinateNode.o CyberX3D/src/cybergarage/x3d/TextureCoordinateNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TextureNode.o: CyberX3D/src/cybergarage/x3d/TextureNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TextureNode.o CyberX3D/src/cybergarage/x3d/TextureNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TextureTransformNode.o: CyberX3D/src/cybergarage/x3d/TextureTransformNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TextureTransformNode.o CyberX3D/src/cybergarage/x3d/TextureTransformNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TimeSensorNode.o: CyberX3D/src/cybergarage/x3d/TimeSensorNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TimeSensorNode.o CyberX3D/src/cybergarage/x3d/TimeSensorNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TimeTriggerNode.o: CyberX3D/src/cybergarage/x3d/TimeTriggerNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TimeTriggerNode.o CyberX3D/src/cybergarage/x3d/TimeTriggerNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TouchSensorNode.o: CyberX3D/src/cybergarage/x3d/TouchSensorNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TouchSensorNode.o CyberX3D/src/cybergarage/x3d/TouchSensorNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Transform2DNode.o: CyberX3D/src/cybergarage/x3d/Transform2DNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/Transform2DNode.o CyberX3D/src/cybergarage/x3d/Transform2DNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TransformNode.o: CyberX3D/src/cybergarage/x3d/TransformNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TransformNode.o CyberX3D/src/cybergarage/x3d/TransformNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TriangleFanSetNode.o: CyberX3D/src/cybergarage/x3d/TriangleFanSetNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TriangleFanSetNode.o CyberX3D/src/cybergarage/x3d/TriangleFanSetNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TriangleSet2DNode.o: CyberX3D/src/cybergarage/x3d/TriangleSet2DNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TriangleSet2DNode.o CyberX3D/src/cybergarage/x3d/TriangleSet2DNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TriangleSetNode.o: CyberX3D/src/cybergarage/x3d/TriangleSetNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TriangleSetNode.o CyberX3D/src/cybergarage/x3d/TriangleSetNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TriangleStripSetNode.o: CyberX3D/src/cybergarage/x3d/TriangleStripSetNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TriangleStripSetNode.o CyberX3D/src/cybergarage/x3d/TriangleStripSetNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TriggerNode.o: CyberX3D/src/cybergarage/x3d/TriggerNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/TriggerNode.o CyberX3D/src/cybergarage/x3d/TriggerNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/UrlFile.o: CyberX3D/src/cybergarage/x3d/UrlFile.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/UrlFile.o CyberX3D/src/cybergarage/x3d/UrlFile.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/VRML97.tab.o: CyberX3D/src/cybergarage/x3d/VRML97.tab.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/VRML97.tab.o CyberX3D/src/cybergarage/x3d/VRML97.tab.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/VRML97.yy.o: CyberX3D/src/cybergarage/x3d/VRML97.yy.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/VRML97.yy.o CyberX3D/src/cybergarage/x3d/VRML97.yy.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/VRML97Parser.o: CyberX3D/src/cybergarage/x3d/VRML97Parser.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/VRML97Parser.o CyberX3D/src/cybergarage/x3d/VRML97Parser.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/VRML97ParserFunc.o: CyberX3D/src/cybergarage/x3d/VRML97ParserFunc.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/VRML97ParserFunc.o CyberX3D/src/cybergarage/x3d/VRML97ParserFunc.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ViewpointNode.o: CyberX3D/src/cybergarage/x3d/ViewpointNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/ViewpointNode.o CyberX3D/src/cybergarage/x3d/ViewpointNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/VisibilitySensorNode.o: CyberX3D/src/cybergarage/x3d/VisibilitySensorNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/VisibilitySensorNode.o CyberX3D/src/cybergarage/x3d/VisibilitySensorNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/WorldInfoNode.o: CyberX3D/src/cybergarage/x3d/WorldInfoNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/WorldInfoNode.o CyberX3D/src/cybergarage/x3d/WorldInfoNode.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/X3DParser.o: CyberX3D/src/cybergarage/x3d/X3DParser.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/X3DParser.o CyberX3D/src/cybergarage/x3d/X3DParser.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/X3DParserHandlers.o: CyberX3D/src/cybergarage/x3d/X3DParserHandlers.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/X3DParserHandlers.o CyberX3D/src/cybergarage/x3d/X3DParserHandlers.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/X3DParserTokenizer.o: CyberX3D/src/cybergarage/x3d/X3DParserTokenizer.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/X3DParserTokenizer.o CyberX3D/src/cybergarage/x3d/X3DParserTokenizer.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/XMLElement.o: CyberX3D/src/cybergarage/x3d/XMLElement.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/XMLElement.o CyberX3D/src/cybergarage/x3d/XMLElement.cpp

${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/XMLNode.o: CyberX3D/src/cybergarage/x3d/XMLNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyberX3D/src/cybergarage/x3d/XMLNode.o CyberX3D/src/cybergarage/x3d/XMLNode.cpp

${OBJECTDIR}/PQP_v1.3/src/BV.o: PQP_v1.3/src/BV.cpp 
	${MKDIR} -p ${OBJECTDIR}/PQP_v1.3/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PQP_v1.3/src/BV.o PQP_v1.3/src/BV.cpp

${OBJECTDIR}/PQP_v1.3/src/Build.o: PQP_v1.3/src/Build.cpp 
	${MKDIR} -p ${OBJECTDIR}/PQP_v1.3/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PQP_v1.3/src/Build.o PQP_v1.3/src/Build.cpp

${OBJECTDIR}/PQP_v1.3/src/PQP.o: PQP_v1.3/src/PQP.cpp 
	${MKDIR} -p ${OBJECTDIR}/PQP_v1.3/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PQP_v1.3/src/PQP.o PQP_v1.3/src/PQP.cpp

${OBJECTDIR}/PQP_v1.3/src/TriDist.o: PQP_v1.3/src/TriDist.cpp 
	${MKDIR} -p ${OBJECTDIR}/PQP_v1.3/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PQP_v1.3/src/TriDist.o PQP_v1.3/src/TriDist.cpp

${OBJECTDIR}/gProximity/Matrix.o: gProximity/Matrix.cpp 
	${MKDIR} -p ${OBJECTDIR}/gProximity
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gProximity/Matrix.o gProximity/Matrix.cpp

${OBJECTDIR}/gProximity/cpu_bvh_constru.o: gProximity/cpu_bvh_constru.cpp 
	${MKDIR} -p ${OBJECTDIR}/gProximity
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gProximity/cpu_bvh_constru.o gProximity/cpu_bvh_constru.cpp

${OBJECTDIR}/gProximity/cuda_make_grid.o: gProximity/cuda_make_grid.cpp 
	${MKDIR} -p ${OBJECTDIR}/gProximity
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gProximity/cuda_make_grid.o gProximity/cuda_make_grid.cpp

${OBJECTDIR}/gProximity/cuda_timer.o: gProximity/cuda_timer.cpp 
	${MKDIR} -p ${OBJECTDIR}/gProximity
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gProximity/cuda_timer.o gProximity/cuda_timer.cpp

${OBJECTDIR}/gProximity/geometry.o: gProximity/geometry.cpp 
	${MKDIR} -p ${OBJECTDIR}/gProximity
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gProximity/geometry.o gProximity/geometry.cpp

${OBJECTDIR}/gProximity/importer_utility.o: gProximity/importer_utility.cpp 
	${MKDIR} -p ${OBJECTDIR}/gProximity
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gProximity/importer_utility.o gProximity/importer_utility.cpp

${OBJECTDIR}/gProximity/main.o: gProximity/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/gProximity
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gProximity/main.o gProximity/main.cpp

${OBJECTDIR}/gProximity/plyfile.o: gProximity/plyfile.c 
	${MKDIR} -p ${OBJECTDIR}/gProximity
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gProximity/plyfile.o gProximity/plyfile.c

${OBJECTDIR}/gProximity/plyfunctions.o: gProximity/plyfunctions.cpp 
	${MKDIR} -p ${OBJECTDIR}/gProximity
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gProximity/plyfunctions.o gProximity/plyfunctions.cpp

${OBJECTDIR}/gProximity/radixsort.o: gProximity/radixsort.cpp 
	${MKDIR} -p ${OBJECTDIR}/gProximity
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gProximity/radixsort.o gProximity/radixsort.cpp

${OBJECTDIR}/gProximity/scene.o: gProximity/scene.cpp 
	${MKDIR} -p ${OBJECTDIR}/gProximity
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gProximity/scene.o gProximity/scene.cpp

${OBJECTDIR}/gProximity/transform.o: gProximity/transform.cpp 
	${MKDIR} -p ${OBJECTDIR}/gProximity
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gProximity/transform.o gProximity/transform.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gproximity

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
