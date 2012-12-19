{
  'targets': [
    {
      'target_name': 'wiringPi',
      'sources': [
        'src/bindings.cc',
        'deps/wiringPi/wiringPi/libwiringPi.a'
      ],
      'include_dirs': [
        'deps/wiringPi/wiringPi'
      ],
      'actions': [
        {
          'action_name': 'MOIKA',
          'inputs': [
          ],
          'outputs': [
            'deps/wiringPi/wiringPi/libwiringPi.a'
          ],
          'action': ['echo', '"EXPERIMENT OUTFILE" > deps/wiringPi/wiringPi/libwiringPi.a']
        }
      ]
    }
  ]
}
