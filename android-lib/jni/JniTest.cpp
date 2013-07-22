﻿/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <dlfcn.h>
#include "sys/syscall.h"
#include "com_type.h"
/* Header for class lib_func_jni_JniTest */


//---------------------------------------------------
// Log
//---------------------------------------------------
#define JNI_DEBUG

#ifdef JNI_DEBUG

#ifndef LOG_TAG
#define LOG_TAG "JNI_DEBUG"
#endif

#include <android/log.h>

#define LOGE(msg) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, msg)
//#define LOGE(format,msg) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG,format, msg)
#define LOGI(msg) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, msg)
#define LOGFI(format,msg) __android_log_print(ANDROID_LOG_INFO, LOG_TAG,format, msg)
#define lOGD(msg) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, msg)
//#define lOGD(format,msg) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG,format, msg)

#endif

/** 将其他类型转换为 string类型。再通过.c_str()转换为 char* 类型。 */
#define SSTR( x ) dynamic_cast< std::ostringstream & >(( std::ostringstream() << std::dec << x ) ).str()
        	
        	
#ifndef _Included_lib_func_jni_JniTest
#define _Included_lib_func_jni_JniTest
#ifdef __cplusplus

#define OUTPUT
#define gettid() syscall(__NR_gettid)


#ifndef NELEM
#define NELEM(x) ((int) (sizeof(x) / sizeof((x)[0])))
#endif

extern "C" {
#endif


jstring chartojstr(JNIEnv* env, const char* pat);
char* jstringTostring(JNIEnv* env, jstring jstr);
S32 ldcls(jclass* jcls,char* bName,JNIEnv *env);
jboolean newObj(JNIEnv*env, jclass cls,jobject * jobj);
jstring getLine(JNIEnv * env, jobject jobj, jstring param);
jint testMax(JNIEnv * env, jclass cls, jint param1,jint param2);
//JNIEnv *JNU_GetEnv();
 
typedef struct Person
{
	jfieldID name;
	jfieldID age;
	jfieldID height;
}PERSON,*LPJ_PERSON;
PERSON sctPerson;


typedef struct JniTest
{
	jmethodID mCallback;
	jmethodID mCallbackInt;
}JNI_TEST,*LPJ_JNI_TEST;
JNI_TEST sctJniTest;


/*
 * used in RegisterNatives to describe native method name, signature,
 * and function pointer.
 typedef struct{
    char *name;
    char *signature;
    void *fnPtr;
}JNINativeMethod;
 
 */


jclass clsPerson,clsJniTest;





//JavaVM* jvm; 

static JNINativeMethod s_methods[] = {
		{"getLine", "(Ljava/lang/String;)Ljava/lang/String;", (void*)getLine},
		{"testMax", "(II)I", (void*)testMax},
		
};

/*
 * Class:  lib_func_jni_JniTest
 * Method: fnwindll
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_lib_func_jni_JniTest_fnwindll
  (JNIEnv * env, jobject jobj){  
  	
  }

/*
 * Class:  lib_func_jni_JniTest
 * Method: getLine
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 
	JNIEXPORT jstring JNICALL Java_lib_func_jni_JniTest_getLine
  (JNIEnv * env, jobject jobj, jstring param)
  
  
 */
 jstring getLine
  (JNIEnv * env, jobject jobj, jstring param){
		char line[300];
		char* paramPtr = jstringTostring(env,param);
		sprintf(line,"getLine: %s ",paramPtr);
		//LOGI("format : %s ",line);
		//return chartojstr(env,line);
		jstring jstr = env->NewStringUTF(line);
		
		 
		jobject objPerson = NULL;
		newObj(env,clsPerson,&objPerson);
		if(objPerson!=NULL){
			LOGFI("[JNI:%d] load objPerson    .... ",gettid());
			env->SetIntField(objPerson, sctPerson.age, 27); 
			env->SetFloatField(objPerson, sctPerson.height, 172.5); 
			env->SetObjectField(objPerson, sctPerson.name, chartojstr(env,"native姓名"));
			env->CallVoidMethod(jobj,sctJniTest.mCallback,1000,objPerson);
			//env->CallVoidMethod(jobj,sctJniTest.mCallbackInt,1000);
			
		}else{
			LOGFI("[JNI:%d] objPerson is null  .... ",gettid());	
		}
		env->DeleteLocalRef(objPerson);
		 
		
		
		/* 
		// 测试local ref的内存管理。
		int i=0;
		jstring tJstr;
		for(;i<1000;i++){
			char tchar[50];
			sprintf(tchar,"lisi....00000000000....%i",i);
			tJstr = env->NewStringUTF(tchar); 	
			LOGFI("new string: %s",jstringTostring(env,tJstr));
			env->DeleteLocalRef(tJstr); 
		}
		*/
		return jstr;

  }

/*
 * Class:  lib_func_jni_JniTest
 * Method: testFloat
 * Signature: (F)F
 */
JNIEXPORT jfloat JNICALL Java_lib_func_jni_JniTest_testFloat
  (JNIEnv * env, jclass cls, jfloat param){
  	LOGFI("Java_lib_func_jni_JniTest_testFloat param:%f...",param);
  	return param;
  }

/*
 * Class:  lib_func_jni_JniTest
 * Method: testDouble
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_lib_func_jni_JniTest_testDouble
  (JNIEnv * env, jclass cls, jdouble param){
  	
  }

/*
 * Class:  lib_func_jni_JniTest
 * Method: testInt
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_lib_func_jni_JniTest_testInt
  (JNIEnv * env, jclass cls, jint param){
  	
  }

/*
 * Class:  lib_func_jni_JniTest
 * Method: testChar
 * Signature: (C)C
 */
JNIEXPORT jchar JNICALL Java_lib_func_jni_JniTest_testChar
  (JNIEnv * env, jclass cls, jchar param){
  		
  }

/*
 * Class:  lib_func_jni_JniTest
 * Method: testShort
 * Signature: (S)S
 */
JNIEXPORT jshort JNICALL Java_lib_func_jni_JniTest_testShort
  (JNIEnv * env, jclass cls, jshort param){
  		
  }

/*
 * Class:  lib_func_jni_JniTest
 * Method: testBoolean
 * Signature: (Z)Z
 */
JNIEXPORT jboolean JNICALL Java_lib_func_jni_JniTest_testBoolean
  (JNIEnv * env, jclass cls, jboolean param){
  	
  }

/*
 * Class:  lib_func_jni_JniTest
 * Method: testLong
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_lib_func_jni_JniTest_testLong
  (JNIEnv * env, jclass cls, jlong param){
  	
  }

/*
 * Class:  lib_func_jni_JniTest
 * Method: testString
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_lib_func_jni_JniTest_testString
  (JNIEnv * env, jclass cls, jstring param){
  		
  }

/*
 * Class:  lib_func_jni_JniTest
 * Method: testStringArray
 * Signature: ([Ljava/lang/String;)[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_lib_func_jni_JniTest_testStringArray
  (JNIEnv * env, jclass cls, jobjectArray param){
  		
  }

/*
 * Class:  lib_func_jni_JniTest
 * Method: testIntArray
 * Signature: ([I)[I
 */
JNIEXPORT jintArray JNICALL Java_lib_func_jni_JniTest_testIntArray
  (JNIEnv * env, jclass cls, jintArray param){
  		
  }

/*
 * Class:  lib_func_jni_JniTest
 * Method: testObject
 * Signature: (Llib/func/jni/Person;)Llib/func/jni/Person;
 */
JNIEXPORT jobject JNICALL Java_lib_func_jni_JniTest_testObject
  (JNIEnv * env, jclass cls, jobject param){
  		
  }

/*
 * Class:  lib_func_jni_JniTest
 * Method: testException
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_lib_func_jni_JniTest_testException
  (JNIEnv * env, jclass cls){}



jint testMax
  (JNIEnv * env, jclass cls, jint param1,jint param2){
  	jint max;
  	max = param1>=param2?param1:param2;
  	char str[100];
  	sprintf(str," testMax: %d,%d  maxVal: %d",param1,param2,max);	
  	LOGI(str);
  	return max;
  }

 
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *jvm, void *reserved)
{
	JNIEnv *env;
	//jvm = _jvm;	 
	S32 ret;
	if (jvm->GetEnv((void**)&env,JNI_VERSION_1_6)) {
		return JNI_ERR;
	}
 
	ret = ldcls(&clsPerson,(char*)"lib/func/jni/Person",env);
	
	/*
	
	LOGI("clsPerson");
	LOGI(SSTR(ret).c_str());
	会报错：error: 'to_string' is not a member of 'std'
	std::string s = std::to_string(ret);
	LOGI(s.c_str());
	*/
	//LOGI(strcat((char*)"clsPerson: ",SSTR(ret).c_str()));
	//LOGI(SSTR(ret).c_str());
	__android_log_print(ANDROID_LOG_INFO, LOG_TAG,"clsPerson: %s ", SSTR(ret).c_str());
	if(ret<0){
		return ret;
	}
	ret = ldcls(&clsJniTest,(char*)"lib/func/jni/JniTest",env);
	__android_log_print(ANDROID_LOG_INFO, LOG_TAG,"clsJniTest: %s ", SSTR(ret).c_str());
 
	//LOGI(strcat((char*)"clsJniTest: ",SSTR(ret).c_str()));
	if(ret<0){
		return ret;
	}
	LOGI("....load class success..... ");
	sctPerson.name = env->GetFieldID(clsPerson, "name", "Ljava/lang/String;");
	
	/*
	clsPerson = env->FindClass("lib/func/jni/Person");
	clsJniTest = env->FindClass("lib/func/jni/JniTest"); 
	*/
	 
	sctPerson.age = env->GetFieldID(clsPerson, "age", "I"); 
	if(env->ExceptionOccurred()){
		LOGI("clsPerson GetFieldID ExceptionOccurred  ");
  	return -1; 
  }else{
  	LOGI("....load GetFieldID  sctPerson.age success..... ");
  } 
	
	 
  sctPerson.height = env->GetFieldID(clsPerson, "height", "F"); 
	if(env->ExceptionOccurred()){
		LOGI("clsPerson GetFieldID ExceptionOccurred  ");
  	return -1; 
  }else{
  	LOGI("....load GetFieldID  sctPerson.height success..... ");
  } 
	 
	/*
	if(clsJniTest == NULL){
			LOGI("clsJniTest is NULL ");
	}
	if(env == NULL){
			LOGI("env is NULL ");
	}
	*/
	sctJniTest.mCallback = env->GetMethodID(clsJniTest,"callback","(ILlib/func/jni/Person;)V");
	sctJniTest.mCallbackInt = env->GetMethodID(clsJniTest,"callbackInt","(I)V");
	if (sctJniTest.mCallback  == NULL) {
		LOGI("sctJniTest.mCallback is NULL ");
		return JNI_ERR;
	}else{
		LOGI("load sctJniTest.mCallback is  success ");	
	}
 	 
	LOGI("....load success..... ");
	
	
	if (env->RegisterNatives(clsJniTest, s_methods, NELEM(s_methods)) < 0)
	{
	  return JNI_ERR;
	}
	LOGI("....registNatives success..... ");
	
	return JNI_VERSION_1_6;
}
JNIEXPORT void JNICALL  
JNI_OnUnload(JavaVM *jvm, void *reserved)
{
	JNIEnv *env;
	S32 ret;
	if (jvm->GetEnv((void**)&env,JNI_VERSION_1_6)) {
		return;
	}
 
	env->DeleteGlobalRef(clsPerson); 
	env->DeleteGlobalRef(clsJniTest); 

	//env->DeleteWeakGlobalRef(clsSyncCI);
	 
	return;
} 

jstring chartojstr(JNIEnv* env, const char* pat)
{
	jclass strClass = env->FindClass("java/lang/String");
	jmethodID ctorID = env->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
	jbyteArray bytes = env->NewByteArray(strlen(pat));
	env->SetByteArrayRegion(bytes, 0, strlen(pat), (jbyte*)pat);
	jstring encoding = env->NewStringUTF("utf-8");
	LOGI("chartojstr    success..... ");
	return (jstring)env->NewObject(strClass, ctorID, bytes, encoding);
}


/***
经过内存管理优化。
***/


char* jstringTostring(JNIEnv* env, jstring jstr)
{
	char* rtn = NULL;
	jclass clsstring = env->FindClass("java/lang/String");
	jstring strencode = env->NewStringUTF("utf-8");
	/*jmethodID 不属于jobject 不需要释放 */
	jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
	jbyteArray barr= (jbyteArray)env->CallObjectMethod(jstr, mid, strencode);
	jsize alen = env->GetArrayLength(barr);
	jbyte* ba = env->GetByteArrayElements(barr, JNI_FALSE);
	if (alen > 0)
	{
		rtn = (char*)malloc(alen + 1);
		memcpy(rtn, ba, alen);
		rtn[alen] = 0;
	}
	
	env->DeleteLocalRef(clsstring);
	env->DeleteLocalRef(strencode);
	env->ReleaseByteArrayElements(barr, ba, 0);
	env->DeleteLocalRef(barr);
	return rtn;
}


S32 ldcls(jclass* pjcls,char* bName,JNIEnv *env){
	jclass cls = env->FindClass(bName);
	if (cls == NULL) {
		return JNI_ERR;
	}
	/* NewWeakGlobalRef ： 好像有问题。*/
	//*pjcls = (jclass)env->NewWeakGlobalRef(cls);
	
	/**
		全局引用保存。
	**/
	*pjcls = (jclass)env->NewGlobalRef(cls);
	if (*pjcls == NULL) {
		return JNI_ERR;
	}
	return 0;
}

jboolean newObj(JNIEnv*env, jclass cls,jobject * jobj){
	LOGFI("[JNI:%d] newObj------  before GetMethodID++++++++++++++++++++++++++  \n",gettid());	
	jmethodID cstrut = env->GetMethodID(cls, "<init>", "()V");
	LOGFI("[JNI:%d] newObj------  after GetMethodID++++++++++++++++++++++++++  \n",gettid());	
	jobject _obj = env->NewObject(cls,cstrut);
  if(env->ExceptionOccurred()){
  	LOGFI("[JNI:%d] ...  newObj fail ....\n",gettid());
  	return 0;
  }
  if(_obj!=NULL){
  	*jobj = _obj;
	}
	return 1;
}

/*
JNIEnv *JNU_GetEnv()
{
	JNIEnv *env = NULL;
	jint sts = jvm->GetEnv((void**)&env,JNI_VERSION_1_6);
	if(sts < 0){
		sts = jvm->AttachCurrentThread((void**)&env,NULL);	
		if(sts <0){
			return NULL;	
		}
		LOGI("jvm AttachCurrentThread...\n");
	}
	return env;
}
*/
#ifdef __cplusplus
}
#endif
#endif