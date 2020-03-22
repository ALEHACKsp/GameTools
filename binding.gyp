{
  "targets": [
    {
      "target_name": "FaceRecognition",
      "sources": [ "FaceRecognition.cpp" ],
      "libraries": [],
      "conditions": [
        [
            "OS == 'win'",
            {
                "link_settings": {
                    "libraries": ["-l ./Dll1.lib",]
                }
            }
        ]
      ]
    }
  ]
}