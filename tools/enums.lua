#!/usr/bin/env lua

local truckboris = require('truckboris')

local function to_snake_case(a_string)
  if not a_string:match('[A-Z]') or not a_string:match('[a-z]') then
    print("no modif")
    return a_string
  else
    s = a_string:gsub("([a-zA-Z]+)([A-Z]+[a-z]+).*","%1_%2")
    s = s:gsub("([a-z]+)([A-Z]+)","%1_%2")
    return s
  end
end


