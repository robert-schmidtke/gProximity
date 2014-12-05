/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	Event.cpp
*
******************************************************************/

#include <cybergarage/x3d/Event.h>

using namespace CyberX3D;

Event::Event(Field *field)
{
	setName(field->getName());
	setTimeStamp(GetCurrentSystemTime());
	setField(field);
	InitializeJavaIDs();
}

Event::Event(char *name, double time, Field *field)
{
	setName(name);
	setTimeStamp(time);
	setField(field);
	InitializeJavaIDs();
}

void Event::InitializeJavaIDs()
{
#ifdef SUPPORT_JSAI
	JNIEnv *jniEnv = GetJniEnv();
	setEventClass(jniEnv->FindClass("vrml/Event"));
#endif
}


////////////////////////////////////////////////
//	Name
////////////////////////////////////////////////

void Event::setName(char *name)
{
	mName.setValue(name);
}

char *Event::getName()
{
	return mName.getValue();
}

////////////////////////////////////////////////
//	Time
////////////////////////////////////////////////

void Event::setTimeStamp(double time)
{
	mTime = time;
}

double Event::getTimeStamp()
{
	return mTime;
}

////////////////////////////////////////////////
//	ConstField
////////////////////////////////////////////////

void Event::setField(Field *field)
{
	mField = field;
}

Field *Event::getField()
{
	return mField;
}

////////////////////////////////////////////////
//	Event::toJavaObject
////////////////////////////////////////////////

#ifdef SUPPORT_JSAI

void Event::setEventClass(jclass eventClass)
{
	mEventClass = eventClass;
}

jclass Event::getEventClass()
{
	return mEventClass;
}

jobject Event::toJavaObject()
{

	JNIEnv *jniEnv = GetJniEnv();
	
	Field	*field = getField();
	jobject	eventField = field->toJavaObject(JAVAOBJECT_CONSTFIELD);
	
	jmethodID intiMethod = jniEnv->GetMethodID(getEventClass(), "<init>", "(Ljava/lang/String;DLvrml/ConstField;)V");
	jstring name = jniEnv->NewStringUTF(field->getName());
	
	jdouble eventTime = GetCurrentSystemTime();
	jobject event = jniEnv->NewObject(getEventClass(), intiMethod, name, eventTime, eventField);
	jniEnv->DeleteLocalRef(eventField);
	jniEnv->DeleteLocalRef(name);
	return event;
}

#endif
