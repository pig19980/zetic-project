import torch
import torch.nn as nn


class SimpleModel(nn.Module):
    def __init__(self):
        super(SimpleModel, self).__init__()
        self.fc1 = nn.Linear(3 * 224 * 224, 256)  # 예시: 224x224 이미지 입력
        self.fc2 = nn.Linear(256, 10)  # 예시: 10개의 클래스를 예측

    def forward(self, x):
        x = x.view(x.size(0), -1)  # 입력을 펼쳐서 FC 계층에 전달
        x = torch.relu(self.fc1(x))
        x = self.fc2(x)
        return x


model = SimpleModel()
example_input = torch.randn(1, 3, 224, 224)
traced_model = torch.jit.trace(model, example_input)
traced_model.save("traced_model.pt")

squeezenet_model = torch.hub.load('pytorch/vision:v0.10.0', 'squeezenet1_1', pretrained=True)
model.eval()
# example_input = torch.randn(1, 3, 244, 244)
scripted_model = torch.jit.script(squeezenet_model, example_input)
scripted_model.save("squeeznet_model.pt")
