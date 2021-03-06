
#include "nuitka/prelude.h"
#include "structseq.h"

// Sentinel PyObject to be used for all our call iterator endings. It will
// become a PyCObject pointing to NULL. It's address is unique, and that's
// enough for us to use it as sentinel value.
PyObject *_sentinel_value = NULL;

PyObject *Nuitka_dunder_compiled_value = NULL;

PyObject *const_int_0;
PyObject *const_str_dot;
PyObject *const_int_pos_1;
PyObject *const_str_empty;
PyObject *const_dict_empty;
PyObject *const_tuple_empty;
PyObject *const_str_plain_rb;
PyObject *const_str_plain_int;
PyObject *const_str_plain_len;
PyObject *const_str_plain_sum;
PyObject *const_str_plain_iter;
PyObject *const_str_plain_long;
PyObject *const_str_plain_name;
PyObject *const_str_plain_open;
PyObject *const_str_plain_read;
PyObject *const_str_plain_repr;
PyObject *const_str_plain_site;
PyObject *const_str_plain_type;
PyObject *const_str_plain_level;
PyObject *const_str_plain_range;
PyObject *const_str_plain_format;
PyObject *const_str_plain_locals;
PyObject *const_str_plain_xrange;
PyObject *const_str_plain___all__;
PyObject *const_str_plain___cmp__;
PyObject *const_str_plain___doc__;
PyObject *const_str_plain_compile;
PyObject *const_str_plain_globals;
PyObject *const_str_plain_inspect;
PyObject *const_str_plain___dict__;
PyObject *const_str_plain___exit__;
PyObject *const_str_plain___file__;
PyObject *const_str_plain___iter__;
PyObject *const_str_plain___main__;
PyObject *const_str_plain___name__;
PyObject *const_str_plain___path__;
PyObject *const_str_plain_exc_type;
PyObject *const_str_plain_fromlist;
PyObject *const_str_plain___class__;
PyObject *const_str_plain___enter__;
PyObject *const_str_plain_bytearray;
PyObject *const_str_plain_exc_value;
PyObject *const_str_plain___import__;
PyObject *const_str_plain___module__;
PyObject *const_str_plain___delattr__;
PyObject *const_str_plain___getattr__;
PyObject *const_str_plain___package__;
PyObject *const_str_plain___setattr__;
PyObject *const_str_plain_classmethod;
PyObject *const_str_plain___builtins__;
PyObject *const_str_plain___compiled__;
PyObject *const_str_plain_staticmethod;
PyObject *const_str_plain___metaclass__;
PyObject *const_str_plain_exc_traceback;
PyObject *const_str_digest_91d422fd0021a0acd73277db22fcb218;
PyObject *const_str_digest_bbf6d4497597e588c1898c426771cc5e;

static void _createGlobalConstants( void )
{
    NUITKA_MAY_BE_UNUSED PyObject *exception_type, *exception_value;
    NUITKA_MAY_BE_UNUSED PyTracebackObject *exception_tb;

#ifdef _MSC_VER
    // Prevent unused warnings in case of simple programs, the attribute
    // NUITKA_MAY_BE_UNUSED doesn't work for MSVC.
    (void *)exception_type; (void *)exception_value; (void *)exception_tb;
#endif

    const_int_0 = PyInt_FromLong( 0l );
    const_str_dot = UNSTREAM_CHAR( 46, 0 );
    const_int_pos_1 = PyInt_FromLong( 1l );
    const_str_empty = UNSTREAM_STRING( &constant_bin[ 0 ], 0, 0 );
    const_dict_empty = _PyDict_NewPresized( 0 );
    assert( PyDict_Size( const_dict_empty ) == 0 );
    const_tuple_empty = PyTuple_New( 0 );
    const_str_plain_rb = UNSTREAM_STRING( &constant_bin[ 2314 ], 2, 1 );
    const_str_plain_int = UNSTREAM_STRING( &constant_bin[ 1159 ], 3, 1 );
    const_str_plain_len = UNSTREAM_STRING( &constant_bin[ 2316 ], 3, 1 );
    const_str_plain_sum = UNSTREAM_STRING( &constant_bin[ 973 ], 3, 1 );
    const_str_plain_iter = UNSTREAM_STRING( &constant_bin[ 2319 ], 4, 1 );
    const_str_plain_long = UNSTREAM_STRING( &constant_bin[ 2323 ], 4, 1 );
    const_str_plain_name = UNSTREAM_STRING( &constant_bin[ 2327 ], 4, 1 );
    const_str_plain_open = UNSTREAM_STRING( &constant_bin[ 2331 ], 4, 1 );
    const_str_plain_read = UNSTREAM_STRING( &constant_bin[ 2335 ], 4, 1 );
    const_str_plain_repr = UNSTREAM_STRING( &constant_bin[ 2339 ], 4, 1 );
    const_str_plain_site = UNSTREAM_STRING( &constant_bin[ 2343 ], 4, 1 );
    const_str_plain_type = UNSTREAM_STRING( &constant_bin[ 2347 ], 4, 1 );
    const_str_plain_level = UNSTREAM_STRING( &constant_bin[ 2351 ], 5, 1 );
    const_str_plain_range = UNSTREAM_STRING( &constant_bin[ 2356 ], 5, 1 );
    const_str_plain_format = UNSTREAM_STRING( &constant_bin[ 2361 ], 6, 1 );
    const_str_plain_locals = UNSTREAM_STRING( &constant_bin[ 2367 ], 6, 1 );
    const_str_plain_xrange = UNSTREAM_STRING( &constant_bin[ 2373 ], 6, 1 );
    const_str_plain___all__ = UNSTREAM_STRING( &constant_bin[ 2379 ], 7, 1 );
    const_str_plain___cmp__ = UNSTREAM_STRING( &constant_bin[ 1590 ], 7, 1 );
    const_str_plain___doc__ = UNSTREAM_STRING( &constant_bin[ 2386 ], 7, 1 );
    const_str_plain_compile = UNSTREAM_STRING( &constant_bin[ 2393 ], 7, 1 );
    const_str_plain_globals = UNSTREAM_STRING( &constant_bin[ 2400 ], 7, 1 );
    const_str_plain_inspect = UNSTREAM_STRING( &constant_bin[ 2407 ], 7, 1 );
    const_str_plain___dict__ = UNSTREAM_STRING( &constant_bin[ 2414 ], 8, 1 );
    const_str_plain___exit__ = UNSTREAM_STRING( &constant_bin[ 2422 ], 8, 1 );
    const_str_plain___file__ = UNSTREAM_STRING( &constant_bin[ 2430 ], 8, 1 );
    const_str_plain___iter__ = UNSTREAM_STRING( &constant_bin[ 2438 ], 8, 1 );
    const_str_plain___main__ = UNSTREAM_STRING( &constant_bin[ 2446 ], 8, 1 );
    const_str_plain___name__ = UNSTREAM_STRING( &constant_bin[ 2454 ], 8, 1 );
    const_str_plain___path__ = UNSTREAM_STRING( &constant_bin[ 2462 ], 8, 1 );
    const_str_plain_exc_type = UNSTREAM_STRING( &constant_bin[ 2470 ], 8, 1 );
    const_str_plain_fromlist = UNSTREAM_STRING( &constant_bin[ 2478 ], 8, 1 );
    const_str_plain___class__ = UNSTREAM_STRING( &constant_bin[ 2486 ], 9, 1 );
    const_str_plain___enter__ = UNSTREAM_STRING( &constant_bin[ 2495 ], 9, 1 );
    const_str_plain_bytearray = UNSTREAM_STRING( &constant_bin[ 2504 ], 9, 1 );
    const_str_plain_exc_value = UNSTREAM_STRING( &constant_bin[ 2513 ], 9, 1 );
    const_str_plain___import__ = UNSTREAM_STRING( &constant_bin[ 2522 ], 10, 1 );
    const_str_plain___module__ = UNSTREAM_STRING( &constant_bin[ 2532 ], 10, 1 );
    const_str_plain___delattr__ = UNSTREAM_STRING( &constant_bin[ 2542 ], 11, 1 );
    const_str_plain___getattr__ = UNSTREAM_STRING( &constant_bin[ 2553 ], 11, 1 );
    const_str_plain___package__ = UNSTREAM_STRING( &constant_bin[ 2564 ], 11, 1 );
    const_str_plain___setattr__ = UNSTREAM_STRING( &constant_bin[ 2575 ], 11, 1 );
    const_str_plain_classmethod = UNSTREAM_STRING( &constant_bin[ 2586 ], 11, 1 );
    const_str_plain___builtins__ = UNSTREAM_STRING( &constant_bin[ 2597 ], 12, 1 );
    const_str_plain___compiled__ = UNSTREAM_STRING( &constant_bin[ 2609 ], 12, 1 );
    const_str_plain_staticmethod = UNSTREAM_STRING( &constant_bin[ 2621 ], 12, 1 );
    const_str_plain___metaclass__ = UNSTREAM_STRING( &constant_bin[ 2633 ], 13, 1 );
    const_str_plain_exc_traceback = UNSTREAM_STRING( &constant_bin[ 2646 ], 13, 1 );
    const_str_digest_91d422fd0021a0acd73277db22fcb218 = UNSTREAM_STRING( &constant_bin[ 2659 ], 49, 0 );
    const_str_digest_bbf6d4497597e588c1898c426771cc5e = UNSTREAM_STRING( &constant_bin[ 2708 ], 92, 0 );

#if _NUITKA_EXE
    /* Set the "sys.executable" path to the original CPython executable. */
    PySys_SetObject(
        (char *)"executable",
        const_str_digest_bbf6d4497597e588c1898c426771cc5e
    );

    /* Set the "sys.executable" path to the original CPython executable. */
    PySys_SetObject(
        (char *)"prefix",
        const_str_digest_91d422fd0021a0acd73277db22fcb218
    );

#endif

    static PyTypeObject Nuitka_VersionInfoType;

    // Same fields as "sys.version_info" except no serial number.
    static PyStructSequence_Field Nuitka_VersionInfoFields[] = {
        {(char *)"major", (char *)"Major release number"},
        {(char *)"minor", (char *)"Minor release number"},
        {(char *)"micro", (char *)"Micro release number"},
        {(char *)"releaselevel", (char *)"'alpha', 'beta', 'candidate', or 'release'"},
        {0}
    };

    static PyStructSequence_Desc Nuitka_VersionInfoDesc = {
        (char *)"__nuitka_version__",                                    /* name */
        (char *)"__compiled__\n\nVersion information as a named tuple.", /* doc */
        Nuitka_VersionInfoFields,                                        /* fields */
        4
    };

    PyStructSequence_InitType(&Nuitka_VersionInfoType, &Nuitka_VersionInfoDesc);

    Nuitka_dunder_compiled_value = PyStructSequence_New(&Nuitka_VersionInfoType);
    assert(Nuitka_dunder_compiled_value != NULL);

    PyStructSequence_SET_ITEM(Nuitka_dunder_compiled_value, 0, PyInt_FromLong(0));
    PyStructSequence_SET_ITEM(Nuitka_dunder_compiled_value, 1, PyInt_FromLong(6));
    PyStructSequence_SET_ITEM(Nuitka_dunder_compiled_value, 2, PyInt_FromLong(2));

#if PYTHON_VERSION < 300
    PyStructSequence_SET_ITEM(Nuitka_dunder_compiled_value, 3, PyString_FromString("release"));
#else
    PyStructSequence_SET_ITEM(Nuitka_dunder_compiled_value, 3, PyUnicode_FromString("release"));
#endif
    // Prevent users from creating the Nuitka version type object.
    Nuitka_VersionInfoType.tp_init = NULL;
    Nuitka_VersionInfoType.tp_new = NULL;


}

// In debug mode we can check that the constants were not tampered with in any
// given moment. We typically do it at program exit, but we can add extra calls
// for sanity.
#ifndef __NUITKA_NO_ASSERT__
void checkGlobalConstants( void )
{

}
#endif

void createGlobalConstants( void )
{
    if ( _sentinel_value == NULL )
    {
#if PYTHON_VERSION < 300
        _sentinel_value = PyCObject_FromVoidPtr( NULL, NULL );
#else
        // The NULL value is not allowed for a capsule, so use something else.
        _sentinel_value = PyCapsule_New( (void *)27, "sentinel", NULL );
#endif
        assert( _sentinel_value );

        _createGlobalConstants();
    }
}
