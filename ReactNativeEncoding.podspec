require "json"

package = JSON.parse(File.read(File.join(__dir__, "package.json")))

Pod::Spec.new do |s|
  s.name         = "react-native-encoding"
  s.version      = package["version"]
  s.summary      = package["description"]
  s.homepage     = package["homepage"]
  s.license      = package["license"]
  s.authors      = package["author"]

  s.platforms    = { :ios => "15.1", :osx => "11.0", :tvos => "15.1", :visionos => "1.0" }
  s.source       = { :git => "https://github.com/mateusz1913/react-native-encoding.git", :tag => "#{s.version}" }

  s.source_files = ["cpp/**/*.{h,hpp,cpp}", "apple/**/*.{h,m,mm}"]

  install_modules_dependencies(s)
end
