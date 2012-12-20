{
  'targets': [
    {
      'target_name': 'wiringPi',
      'sources': [
        'src/bindings.cc'
      ],
      'include_dirs': [
        'deps'
      ],
      'libraries': [
        '<!(pwd)/deps/libwiringPi.a'
      ],
      'cflags': [
        '-Wall'
      ]
    }
  ]
}
