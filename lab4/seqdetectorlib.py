# Lab 4

# type of FSM called a sequence detector
class seqdetector:
   
   def __init__(self):
      self.state = "NULL"   
      self.combination_lock = ["here", "are", "the", "solutions", "to", "the", "next", "exam"]

   def evolve(self,word):
      if (self.state == "NULL" and word == "here"):
         self.state = "1st_state"
      elif (self.state == "1st_state" and word == "are"):
         self.state = "2nd_state"
      elif (self.state == "2nd_state" and word == "the"):
         self.state = "3rd_state"
      elif (self.state == "3rd_state" and word == "solutions"): 
         self.state = "4th_state"
      elif (self.state == "4th_state" and word == "to"):
         self.state = "5th_state"
      elif (self.state == "5th_state" and word == "the"):
         self.state = "6th_state"
      elif (self.state == "6th_state" and word == "next"):
         self.state = "7th_state"
      elif (self.state == "7th_state" and word == "exam"):
         self.state = "DETECTED"
      else:
         self.state = "NULL"

      if self.state == "DETECTED":
         self.state = "NULL"
         return True
      else:
         return False