import { ComponentFixture, TestBed } from '@angular/core/testing';

import { WojewodztwoComponent } from './wojewodztwo.component';

describe('WojewodztwoComponent', () => {
  let component: WojewodztwoComponent;
  let fixture: ComponentFixture<WojewodztwoComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ WojewodztwoComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(WojewodztwoComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
