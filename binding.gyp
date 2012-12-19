{
  'targets': [
    {
      'target_name': 'wiringPi',
      'sources': [
        'src/bindings.cc',
        'deps/libwiringPi.a'
      ],
      'include_dirs': [
        'deps'
      ]
    }
  ]
}
